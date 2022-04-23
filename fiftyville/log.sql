-- NOTES:

--     3 witnesses:
--         Ruth (saw he got into a car, left the bakery parking lot 10 mins after theft).
--         Eugene (recognized him, saw him withdraw money from ATM on leggett Street).
--         Raymond (heard the theif making a phonecall, asked recipient to purchase plane ticket for July 29th, 2021).

--     What we Know:
--         - Theft occured on July 28, 2021 at 10:15am
--         - Theft took place on Humphrey Street at the Humphrey St Bakery.
--         - Emma (presumed owner of the bakery)
--         - A total of 8 cars were seen leaving the bakery 10 mins after the theft.
--             - Those 8 suspects are Vanessa, Barry, Iman, Sofia, Luca, Diana, Kelsey, Bruce
--         - A total of 8 withdrawals were made on Leggett St on the day of the crime.
--             - Those 8 are Kenny, Iman, Benista, Taylor, Brooke, Luca, Diana, and Bruce
--         - A total of 8 people made phone calls of < 1 min in length on the day/time of the crime.
--             - Those 8 are Kenny Sofia, Benista, Taylor, Diana, Kelsey, Bruce, and Carina.


-- Check the crime scene reports from July 28, on Humphrey St.
SELECT description
FROM crime_scene_reports
WHERE street = "Humphrey Street"
AND year = 2021 AND month = 7 AND day = 28;

-- Check eye-witness transcripts.
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
WHERE hour = 10
AND minute > 15
AND minute < 26
AND year = 2021 AND month = 7 AND day = 28;

--Find people with those licsense plates
SELECT name
FROM people
WHERE license_plate IN
    (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE hour = 10
        AND minute > 15
        AND minute < 26
        AND year = 2021 AND month = 7 AND day = 28
    );

-- Eugene recommends checking ATM withdrawal logs on Leggett Street
SELECT
    account_number,
    amount,
    transaction_type
FROM atm_transactions
WHERE atm_location = "Leggett Street"
AND transaction_type = "withdraw"
AND year = 2021 AND month = 7 AND day = 28;

-- Find all people with those account numbers
SELECT
    name,
    id
FROM people
WHERE id IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE atm_location = "Leggett Street"
        AND transaction_type = "withdraw"
        AND year = 2021 AND month = 7 AND day = 28
    )
);

-- Finally, Raymond heard the thief making a call to purchase a plane ticket for July 29th.
-- The flight is described to be the earlist flight out of fiftyville tomorrow
SELECT *
FROM phone_calls
WHERE duration < 60
AND year = 2021 AND month = 7 AND day = 28
ORDER BY id;

-- Find all people with those phone numbers
SELECT name
FROM people
WHERE phone_number IN
(
    SELECT caller
    FROM phone_calls
    WHERE duration < 60
    AND year = 2021 AND month = 7 AND day = 28
    ORDER BY id
);

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

-- At this point we know the remaining suspects are Bruce and Diana,
-- List the flights passenger passport numbers against theirs.
SELECT *
FROM passengers
WHERE flight_id = 36
and passport_number IN
    (
        SELECT passport_number
        FROM people
        WHERE name IN ("Bruce", "Diane")
    );

SELECT name, passport_number FROM people WHERE name IN ("Bruce", "Diana");

-- And there we have it, since diana was not on the flight, Bruce is our thief!
-- Now that We know who


