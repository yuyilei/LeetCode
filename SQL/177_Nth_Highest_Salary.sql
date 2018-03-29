CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N = N - 1 ;  /* limit 里面不能用 N - 1，所以要设置 为 N-1 */ 
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary 
      from Employee 
      order by Salary desc 
      limit N, 1 
  );
END

/*使用distinct 去除相同的项，因为题目要求是求出第N大的数据
  order by 使用 desc 进行降序排序，其实我有点奇怪，书上说order by子句必须是select子句的最后一个子句，可是这里最后一个子句是limit也可以
  limit 子句后面的两个参数分别是 offset和数量，offset从0开始，如果没有的话会返回null 
 */