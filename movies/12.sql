-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

-- SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN ((SELECT id FROM people WHERE name = "Johnny Depp") AND (SELECT id FROM people WHERE name = "Helena Bonham Carter")));

-- SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Johnny Depp")) AND
--  (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Helena Bonham Carter"));

-- select movie_id where johnny and helena IN

-- -- Try this
-- Select movie id where id = (select id of all jonny movies) = (select id's of all helans movies)';
-- SELECT title FROM movies WHERE id IN ((SELECT ))
-- -- Yikes

-- title from Movies where id in
--     (movie_id from stars where person_id in
--         (id from people where name = "Johnny Depp")
-- AND

-- SELECT stars.movie_id FROM stars INNER JOIN stars ON
--     (SELECT movie_id FROM stars WHERE person_id IN (SELECT ID FROM people WHERE name = "Johnny Depp"))
--      =
--     (SELECT movie_id FROM stars WHERE person_id IN (SELECT ID FROM people WHERE name = "Helena Bonham Carter"));


-- SELECT movie_id FROM stars INNER JOIN stars ON (SELECT movie_id FROM stars WHERE person_id IN (SELECT ID FROM people WHERE name = "Johnny Depp")) = (SELECT movie_id FROM stars WHERE person_id IN (SELECT ID FROM people WHERE name = "Helena Bonham Carter"));

-- SELECT movies.title from movies INNER JOIN stars ON movies.id = stars.movie_id WHERE movies.id IN ();

-- Select movie id from stars where movie id in (list all movie ids of johnny depp) AND (list all movies of helena)
-- Select id from johnny movies where id in (select id of all of helnas movies)

-- SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name IN ("Johnny Depp", "Helena Bonham Carter")));

SELECT title FROM movies WHERE id IN
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Johnny Depp") IN
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Helena Bonham Carter"))) ORDER BY title;

SELECT title FROM movies WHERE id IN
(SELECT movie_id FROM (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Johnny Depp") WHERE movie_id IN
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Helena Bonham Carter")))) ORDER BY title;

SELECT title FROM movies GROUP BY title HAVING
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Johnny Depp") IN
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Helena Bonham Carter"))) ORDER BY title;