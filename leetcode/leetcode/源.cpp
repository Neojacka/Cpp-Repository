#define _CRT_SECURE_NO_WARNINGS 1
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{

    int i = 0, j = 0, m = 0;
    int arr[2000];
    while (i < nums1Size && j<nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            arr[m++] = nums1[i++];
        }
        else
        {
            arr[m++] = nums2[j++];
        }
    }
    while (i < nums1Size)
    {
        arr[m++] = nums1[i++];
    }
    while (j < nums2Size)
    {
        arr[m++] = nums2[j++];
    }
    double mid;
    if (m % 2 != 0 && m > 1)
    {
        mid = arr[m / 2] + arr[m / 2 - 1];
    }
    else
        mid = arr[m / 2];

    return mid;
}
int main()
{
    int num1[3] = { 1,2,3 };
    int num2[2] = { 2,1 };
    findMedianSortedArrays(num1,3,num2,2);
}