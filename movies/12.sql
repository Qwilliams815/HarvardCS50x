-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

SELECT title FROM movies WHERE id IN
 (SELECT movie_id FROM stars WHERE person_id IN
 (SELECT id FROM people WHERE name IN ("Johnny Depp", "Helena Bonham Carter"))
 GROUP BY movie_id HAVING COUNT(*) > 1);

-- ERROR IN DATABASE, DOES NOT LIST HELENA AS A CHARACTER IN LONE RANGER
-- SELECT title, id FROM movies WHERE title LIKE "%Lone Ranger%";

-- SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id = 1210819);
