NOTES:
    What we Know:
        - theft took place on July 28, 2021 at 10:15am
        - and that it took place on Humphrey Street at the Humphrey St Bakery.
        - Emma (owner of the bakery)
        - A total of 8 cars were seen leaving the bakery 10 mins after the theft.
            - Those 8 suspects are Vanessa, Barry, Iman, Sofia, Luca, Diana, Kelsey, Bruce

    3 witnesses:
        Ruth (saw he got into a car, left the bakery parking lot 10 mins after theft).
        Eugene (recognized him, saw him withdraw money from ATM on leggett Street).
        Raymond (heard the theif making a phonecall, asked recipient to purchase plane ticket for July 29th, 2021).

-- Check the crime scene reports from July 28, on Humphrey St.
SELECT description
FROM crime_scene_reports
WHERE year = 2021
AND street = "Humphrey Street";

-- Check eye-witness reviews
SELECT
    name,
    transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;

-- Ruth recommends checking the bakery parking lot security logs
SELECT
    hour,
    minute,
    activity,
    license_plate
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28;

--Find people with those licsense plates
SELECT name
FROM people
WHERE license_plate IN
    (
        "5P2BI95",
        "94KL13X",
        "6P58WS2",
        "4328GD8",
        "G412CB7",
        "L93JTIZ",
        "322W7JE",
        "0NTHK55"
    )

-- Eugene recommends checking ATM withdrawal logs on Leggett Street
SELECT
    account_number,
    amount,
    transaction_type
FROM atm_transactions
WHERE atm_location = "Leggett Street"
AND year = 2021 AND month = 7 AND day = 28
ORDER BY account_number;

-- Finally, Raymond heard the thief making a call to purchase a plane ticket for July 29th.
-- The flight is described to be the earlist flight out of fiftyville tomorrow
SELECT *
FROM phone_calls
WHERE duration < 60
AND year = 2021 AND month = 7 AND day = 28
ORDER BY id;

-- The flight is described to be the earlist flight out of fiftyville tomorrow
SELECT *
FROM flights
WHERE origin_airport_id =
    (
        SELECT id
        FROM airports
        WHERE full_name = "Fiftyville Regional Airport"
    )
    AND year = 2021 AND month = 7 AND day = 29
    ORDER BY hour;

-- Find destination using destination_airport_id 4 (LaGuardia Airport | New York City)
SELECT
    full_name,
    city
FROM airports
WHERE id = 4;
