-- List the names of all people who starred in Toy Story.
SELECT name FROM people WHERE id IN (SELECT id FROM movies WHERE title = "Toy Story");

Toy story has an id