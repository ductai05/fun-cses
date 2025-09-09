### Bài 1746: Array Description
Một dãy có n số, giá trị từ 1 đến m. Trị tuyệt đối hiệu 2 phần tử liền kề <= 1.
Đếm số dãy thỏa dãy cho trước. 0 đại diện cho phần tử chưa biết.

=> Xây dựng dp[i][x]: số dãy từ 1 đến i, a[i] = x thỏa ycbt
=> dp[i][x] = dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1], với 1 <= x <= m; i >= 2
Giá trị ban đầu: Với a[1] = 0 => dp[i][x] = 1 với mọi x
                 Với a[1] = k != 0 => dp[i][x] = (x == k)

=> Đáp án cuối: sigma dp[n][x] với 1 <= x <= m

Ví dụ: Với mảng [0, 2, 0], n = 3, m = 3:
- dp[1][x] = 1 với mọi 1 <= x <= 3; 
- dp[2][2] = dp[1][1] + dp[1][2] + dp[1][3] = 1 + 1 + 1 = 3 (loại các dp[2][x] khác vì phần tử 2 luôn bằng 2) 
- dp[3][1] = dp[2][1] + dp[2][2] = 0 + 3 = 3. 
- dp[3][2] = dp[2][1] + dp[2][2] + dp[2][3] = 0 + 3 + 0 = 3. 
- dp[3][3] = dp[2][2] + dp[2][3] = 3 + 0 = 3 
=> res = 3 + 3 + 3 = 9.