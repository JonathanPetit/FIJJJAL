from pirc522 import RFID
import RPi.GPIO as GPIO
import time

try:
    GPIO.cleanup()
except Exception as e:
    print(e)

rdr = RFID()

util = rdr.util()
try:
    while True:
        # Wait for tag
        rdr.wait_for_tag()
        
        # Request tag
        (error, data) = rdr.request()
        
        if not error:
            print("\nTag detected")
            (error, uid) = rdr.anticoll()
            if not error:
                # Print UID
                print("Card read UID: " + str(uid))

                # Set tag as used in util. This will call RFID.select_tag(uid)
                util.set_tag(uid)
                # We can change authorization info if you have different key in other sector
                util.auth(rdr.auth_a, [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF])
                # If you want to use methods from RFID itself, you can use this for authorization
                # This will authorize for block 1 of sector 2 -> block 9
                # This is once more called only if it's not already authorized for this block
                util.do_auth(util.block_addr(2, 1))
                # Now we can do some "lower-level" stuff with block 9

                # Ask the seller to enter the latitude and the longitude of the delivery place
                latitude = input("Veuillez entrer la latitude (ex: +48,3465) (N --> + / S --> -) : \n")
                longitude = input("Veuillez entrer la longitude (ex: +150,4554) (E --> + / O --> -) : \n")
                latitude_split = latitude[1:].split(",")
                longitude_split = longitude[1:].split(",")

                if ("-" in latitude):
                    latitude_sign = 0
                else:
                    latitude_sign = 255

                latitude_integer = int(latitude_split[0])
                latitude_decimal = latitude_split[1]
                
                # Allow us to have always 6 decimals and easily put it in the RFID card
                if (len(latitude_decimal) < 6):
                    number_zero = 6 - len(latitude_decimal)
                    while (number_zero != 0):
                        latitude_decimal += "0"
                        number_zero -= 1

                latitude_decimal1 = int(latitude_decimal[0:2])
                latitude_decimal2 = int(latitude_decimal[2:4])
                latitude_decimal3 = int(latitude_decimal[4:6])

                if ("-" in longitude):
                    longitude_sign = 0
                else:
                    longitude_sign = 255

                longitude_integer = int(longitude_split[0])
                longitude_decimal = longitude_split[1]

                if (len(longitude_decimal) < 6):
                    number_zero = 6 - len(longitude_decimal)
                    while (number_zero != 0):
                        longitude_decimal += "0"
                        number_zero -= 1

                longitude_decimal1 = int(longitude_decimal[0:2])
                longitude_decimal2 = int(longitude_decimal[2:4])
                longitude_decimal3 = int(longitude_decimal[4:6])

                # Uncomment this line to write all the bytes of the block 9
                #rdr.write(9, [latitude_sign, latitude_integer, latitude_decimal, longitude_sign, longitude_integer, longitude_decimal, 0x76, 0x54, 0x32, 0x10, 0x69, 0x27, 0x46, 0x66, 0x66, 0x64])

                # We can rewrite specific bytes in block using this method. None means "don't change this byte"
                # Note that this won't do authorization, because we've already called do_auth for block 9
                util.rewrite(9, [latitude_sign, latitude_integer, latitude_decimal1, latitude_decimal2, latitude_decimal3, longitude_sign, longitude_integer, longitude_decimal1, longitude_decimal2, longitude_decimal3])
                # This will write S2B1: [0xFF, 0x23, 0xAB, 0xCD, 0xEF, 0x98, 0x76......]
                util.read_out(9)

                # We must stop crypto
                util.deauth()
                rdr.cleanup()

                time.sleep(2)

        rdr2 = RFID()

        while True:
            rdr2.wait_for_tag()

            (error, data) = rdr2.request()
            
            if not error:
                print("\nTag detected")
                (error, uid2) = rdr2.anticoll()

                if not error:
                    # Print UID
                    print("Card read UID: " + str(uid2))

                    # Set tag as used in util. This will call RFID.select_tag(uid)
                    util.set_tag(uid2)
                    # We can change authorization info if you have different key in other sector
                    util.auth(rdr.auth_a, [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF])
                    #If you want to use methods from RFID itself, you can use this for authorization
                    # This will authorize for block 2 of sector 2 -> block 9
                    # This is once more called only if it's not already authorized for this block
                    util.do_auth(util.block_addr(2, 1))
                    # Now we can do some "lower-level" stuff with block 9

                    # Uncomment this line to write all the bytes of the block 9
                    #rdr.write(9, [latitude_sign, latitude_integer, latitude_decimal, longitude_sign, longitude_integer, longitude_decimal, 0x76, 0x54, 0x32, 0x10, 0x69, 0x27, 0x46, 0x66, 0x66, 0x64])

                    # We rewrite specific bytes with the uid of the previous RFID tag                    
                    util.rewrite(9, [uid[0], uid[1], uid[2], uid[3], uid[4]])
                    util.read_out(9)

                    # We must stop crypto
                    util.deauth()
                    break

        # Calls GPIO cleanup
        rdr2.cleanup()

        time.sleep(2)

except KeyboardInterrupt:
    GPIO.cleanup()
