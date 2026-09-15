# Write your MySQL query statement below
SELECT name, COALESCE(sum(distance), 0) AS travelled_distance 
FROM Users u
LEFT JOIN Rides r
ON u.id = r.user_id  
GROUP BY u.id, name
ORDER BY sum(distance) DESC,
    name ASC