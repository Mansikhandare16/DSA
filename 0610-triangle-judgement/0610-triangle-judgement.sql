# Write your MySQL query statement below
select x, y, z, if((x+y > z) and (y + z > x) and (x + z > y), "Yes", "No") as `triangle`
from triangle

# logic is that two line segment's sum should be greater than third line segment's sum