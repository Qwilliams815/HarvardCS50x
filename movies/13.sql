-- List the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT name FROM people WHERE id IN
(SELECT person_id FROM stars)