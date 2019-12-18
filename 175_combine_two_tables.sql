--   表1: Person
--
--   +-------------+---------+
--   | 列名         | 类型     |
--   +-------------+---------+
--   | PersonId    | int     |
--   | FirstName   | varchar |
--   | LastName    | varchar |
--   +-------------+---------+
--   PersonId 是上表主键
--   表2: Address
--
--   +-------------+---------+
--   | 列名         | 类型    |
--   +-------------+---------+
--   | AddressId   | int     |
--   | PersonId    | int     |
--   | City        | varchar |
--   | State       | varchar |
--   +-------------+---------+
--   AddressId 是上表主键
--
-- 基于上述两表提供 person 的以下信息 FirstName, LastName, City, State


select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId
