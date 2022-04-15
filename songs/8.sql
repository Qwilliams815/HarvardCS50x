-- Lists the names of the songs that feature other artists (feat. artists)
SELECT name FROM songs where name LIKE "%feat%";