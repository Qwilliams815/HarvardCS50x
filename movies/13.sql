-- List the names of all people who starred in a movie in which Kevin Bacon also starred.
select all people in movie where movie id IN (find all movies that kevin bacon was in)

SELECT name FROM people WHERE id IN
(SELECT person_id FROM stars WHERE )


SELECT name FROM people WHERE id IN
 (SELECT person_id FROM stars WHERE movie_id IN
 ((SELECT movie_id from STARS where person_id = (SELECT id FROM people WHERE name = "Kevin Bacon"))));

SELECT movie_id from STARS where person_id = (SELECT id FROM people WHERE name = "Kevin Bacon");

