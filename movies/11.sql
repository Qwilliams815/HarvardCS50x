-- List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
SELECT name FROM movies WHERE id IN
(SELECT movie_id FROM ratings WHERE movie_id IN
(SELECT id FROM people WHERE name = "Chadwick Boseman"))

Movies -> rated highly -> with chadwick -> orderby rating desc -> limit 5

SELECT title FROM movies WHERE id IN (SELECT movie_id FROM ratings ORDER BY rating) LIMIT 10;