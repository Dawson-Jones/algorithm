int trap(int *height, int heightSize) {
    int ans = 0;
    int l = 0, r = heightSize - 1;
    int l_m = 0, r_m = 0;
    while (l < r) {
        l_m = fmax(l_m, height[l]);
        r_m = fmax(r_m, height[r]);
        if (height[l] < height[r]) {
            ans += l_m - height[l];
            l++;
        } else {
            ans += r_m - height[r];
            r--;
        }
    }
    return ans;
}
