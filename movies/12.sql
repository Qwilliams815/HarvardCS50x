-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN ((SELECT id FROM people WHERE name = "Johnny Depp") AND (SELECT id FROM people WHERE name = "Helena Bonham Carter")));

SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Johnny Depp")) AND
 (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Helena Bonham Carter"));

select movie_id where johnny and helena IN

-- Try this
Select movie id where id = (select id of all jonny movies) = (select id's of all helans movies)';
SELECT title FROM movies WHERE id IN ((SELECT ))
-- Yikes

title from Movies where id in
    (movie_id from stars where person_id in
        (id from people where name = "Johnny Depp")
AND

SELECT movie_id FROM stars WHERE
    (SELECT movie_id FROM stars WHERE person_id IN (SELECT ID FROM people WHERE name = "Johnny Depp"))
     =
    (SELECT movie_id FROM stars WHERE person_id IN (SELECT ID FROM people WHERE name = "Helena Bonham Carter"));