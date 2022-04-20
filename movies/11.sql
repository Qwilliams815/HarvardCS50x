-- List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
SELECT movies.title
FROM movies
INNER JOIN ratings
ON ratings.movie_id = movies.id
WHERE id IN
    (SELECT movie_id
    FROM ratings
    WHERE movie_id IN
        (SELECT movie_id
        FROM stars
        WHERE person_id =
            (SELECT id
            FROM people
            WHERE name = "Chadwick Boseman")))
ORDER BY rating DESC
LIMIT 5;