-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- (Error in database, does not list Helena Bonham Carter as co-star in Lone Ranger)

SELECT title
FROM movies
WHERE id IN
    (SELECT movie_id
    FROM stars
    WHERE person_id IN
        (SELECT id
        FROM people
        WHERE name IN
        ("Johnny Depp", "Helena Bonham Carter"))
    GROUP BY movie_id HAVING COUNT(*) > 1);
