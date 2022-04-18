-- Determine the average rating of all movies released in 2012
-- SELECT AVG(rating) FROM ratings WHERE movie_id == (SELECT id FROM movies WHERE year = 2012);
SELECT AVG(rating) FROM ratings WHERE movie_id = 2012;
SELECT id FROM movies WHERE year = 2012;

SELECT id FROM movies LIMIT 10;
SELECT movie_id FROM ratings LIMIT 10;