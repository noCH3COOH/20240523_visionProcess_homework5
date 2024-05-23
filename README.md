# 卷积算法实践

## 1. 实验目标

根据图像卷积公式，实现 C++ 函数用于图像卷积

## 2. 实现方案

1. 搜集常用卷积核
2. 使用 openCV 对图像数据进行读入
3. 使用编写的图像卷积函数对图像进行卷积，

* 使用公式为

$$ SRC(x,y) = \sum_{m=-{a_x}}^{a_x} \sum_{n=-{a_y}}^{a_y} SRC(x+m, y+n) \times Kernel(m+a_x, n+a_y), \quad a_x = int(kernel.width / 2),  a_y = int(kernel.height / 2) $$

* 搜集卷积核有：

1. 平滑滤波卷积核

$$
\left[
\begin{matrix}
1 \over 9 & 1 \over 9 & 1 \over 9 \\
1 \over 9 & 1 \over 9 & 1 \over 9 \\
1 \over 9 & 1 \over 9 & 1 \over 9
\end{matrix}
\right]
$$

2. 高斯模糊卷积核：
    
$$
\left[
\begin{matrix}
1 \over 16 & 2 \over 16 & 1 \over 16 \\
2 \over 16 & 4 \over 16 & 2 \over 16 \\
1 \over 16 & 2 \over 16 & 1 \over 16
\end{matrix}
\right]
$$

3. 锐化卷积核：
    
$$
\left[
\begin{matrix}
-1 & -1 & -1 \\
-1 &  9 & -1 \\
-1 & -1 & -1
\end{matrix}
\right]
$$

4. Sobel X方向卷积核：
    
$$
\left[
\begin{matrix}
-1 & 0 & 1 \\
-2 & 0 & 2 \\
-1 & 0 & 1
\end{matrix}
\right]
$$

5. Sobel Y方向卷积核：
    
$$
\left[
\begin{matrix}
-1 & -2 & -1 \\
 0 &  0 &  0 \\
 1 &  2 &  1
\end{matrix}
\right]
$$

6. 左上Sobel卷积核：
    
$$
\left[
\begin{matrix}
 2 &  1 &  0 \\
 1 &  0 & -1 \\
 0 & -1 & -2
\end{matrix}
\right]
$$

7. 右上Sobel卷积核：
    
$$
\left[
\begin{matrix}
 0 &  1 &  2 \\
-1 &  0 &  1 \\
-2 & -1 &  0
\end{matrix}
\right]
$$

8. 拉普拉斯卷积核：
    
$$
\left[
\begin{matrix}
 0 & -1 &  0 \\
-1 &  4 & -1 \\
 0 & -1 &  0
\end{matrix}
\right]
$$

9. 8连通拉普拉斯卷积核：
    
$$
\left[
\begin{matrix}
 1 &  1 &  1 \\
 1 & -8 &  1 \\
 1 &  1 &  1
\end{matrix}
\right]
$$

10. 浮雕卷积核：
    
$$
\left[
\begin{matrix}
-2 & -1 &  0 \\
-1 &  1 &  1 \\
 0 &  1 &  2
\end{matrix}
\right]
$$

11. 另一种浮雕卷积核：
    
$$
\left[
\begin{matrix}
-1 & -1 &  0 \\
-1 &  0 &  1 \\
 0 &  1 &  1
\end{matrix}
\right]
$$

12. Prewitt X方向卷积核：
    
$$
\left[
\begin{matrix}
-1 &  0 &  1 \\
-1 &  0 &  1 \\
-1 &  0 &  1
\end{matrix}
\right]
$$

13. Prewitt Y方向卷积核：
    
$$
\left[
\begin{matrix}
-1 & -1 & -1 \\
 0 &  0 &  0 \\
 1 &  1 &  1
\end{matrix}
\right]
$$

14. Prewitt 左上卷积核：
    
$$
\left[
\begin{matrix}
 1 &  1 &  0 \\
 1 &  0 & -1 \\
 0 & -1 & -1
\end{matrix}
\right]
$$

15. Prewitt 右上卷积核：
    
$$
\left[
\begin{matrix}
 0 &  1 &  1 \\
-1 &  0 &  1 \\
-1 & -1 &  0
\end{matrix}
\right]
$$

16. 高通卷积核：
    
$$
\left[
\begin{matrix}
-1 & -1 & -1 \\
-1 &  8 & -1 \\
-1 & -1 & -1
\end{matrix}
\right]
$$

17. Scharr X方向卷积核：
    
$$
\left[
\begin{matrix}
-3 &  0 &  3 \\
10 &  0 & 10 \\
-3 &  0 &  3
\end{matrix}
\right]
$$

18. Scharr Y方向卷积核：
    
$$
\left[
\begin{matrix}
-3 & -10 & -3 \\
 0 &   0 &  0 \\
 3 &  10 &  3
\end{matrix}
\right]
$$

19. LoG卷积核（Laplacian of Gaussian）：
    
$$
\left[
\begin{matrix}
 0 &  0 &  1 &  0 &  0 \\
 0 &  1 &  2 &  1 &  0 \\
 1 &  2 & -16 &  2 &  1 \\
 0 &  1 &  2 &  1 &  0 \\
 0 &  0 &  1 &  0 &  0
\end{matrix}
\right]
$$

## 3. 实现结果



## 4. 收获心得
