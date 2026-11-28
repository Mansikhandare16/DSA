# Write your MySQL query statement below
SELECT DISTINCT s.id, s.visit_date, s.people
FROM Stadium s
JOIN(
    SELECT id 
    FROM(
        SELECT id, LAG(id) OVER(ORDER BY id) AS prev, LEAD(id) OVER(ORDER BY id) AS next
        FROM Stadium
        WHERE people>=100
    )t
    WHERE prev=id-1 AND next=id+1
)v
ON s.id BETWEEN v.id-1 AND v.id+1
WHERE s.people>=100
ORDER BY visit_date;