# Write your MySQL query statement below
SELECT w2.id
FROM Weather w2
JOIN Weather w1
ON DATEDIFF(w2.recordDate,w1.recordDate)=1
WHERE w2.temperature>w1.temperature;