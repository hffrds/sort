https : // blog.csdn.net/alzzw/article/details/98100378

#include <algorithm> //基础类型不用包含

void sort(int array1[], int m){  // selection sort                   sizeof不适用于动态数组
    int n = 0, p = 0;
    for (int i = 0; i < m - 1; i++)
    {
        p = i;
        for (n = i + 1; n < m; n++)
        {
            p = ((array1[n] > array1[p]) ? p : n);
        }
        swap(array1[i], array1[p]);
    }
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <algorithm>
#include <vector>
void Bubblesort(std::vector<int> &vec) 
{ // 冒泡排序
    int m = vec.size();
    for (int i = 0; i < m - 1; i++)
    {
        bool swapped = false;
        for (int n = 0; n < m - i - 1; n++)
        {
            if (vec[n] > vec[n + 1])
            {
                std::swap(vec[n], vec[n + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
void Insert_Sort(int *arr, int n) // 插入排序
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <iostream>
#include <vector>
using namespace std;

// 切分函数：选择一个基准值，将数组分为两个部分，左边小于基准值，右边大于等于基准值
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // 选择最后一个元素作为基准值
    int i = low - 1;       // i 是比基准值小的元素的最后一个位置

    // 遍历整个数组，将小于基准值的元素交换到左边，大于基准值的元素交换到右边
    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    // 将基准值放到合适的位置
    swap(arr[i + 1], arr[high]);

    // 返回基准值的位置
    return i + 1;
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
                                                                                                                                                                              // 快速排序函数
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // 切分数组并获取基准值的位置
        int pi = partition(arr, low, high);

        // 递归排序基准值左边和右边的子数组
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "原始数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "排序后的数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <iostream> //归并排序
#include <vector>

using namespace std;

// 合并两个已排序的子数组
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // 左子数组的大小
    int n2 = right - mid;    // 右子数组的大小

    // 创建临时数组存储左右两个子数组
    vector<int> L(n1), R(n2);

    // 复制数据到临时数组 L 和 R
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    // 合并两个子数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // 复制剩余元素（如果有的话）
    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// 归并排序主函数
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // 计算中点

        // 递归排序左右子数组
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并已排序的子数组
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "原始数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "排序后的数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <iostream> //堆排序
#include <vector>

using namespace std;

// 调整堆，使其满足最大堆性质
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // 将当前节点视为最大节点
    int left = 2 * i + 1;  // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点比当前节点大，则更新最大节点
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // 如果右子节点比当前最大节点大，则更新最大节点
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // 如果最大节点不是当前节点，则交换，并递归调整子树
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // 建立最大堆
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    // 交换根节点（最大值）与最后一个节点，并重新调整堆
    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]); // 将最大值放到数组末尾
        heapify(arr, i, 0);   // 调整堆，确保根节点仍然是最大值
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "原始数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "排序后的数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <iostream> //基数排序
#include <vector>
#include <algorithm> // 用于std::max函数

using namespace std;

// 获取数字的某一位上的值
int getDigit(int num, int digit)
{
    return (num / static_cast<int>(pow(10, digit))) % 10;
}

// 计数排序基于指定的位（digit）
void countingSort(vector<int> &arr, int n, int digit)
{
    vector<int> output(n);    // 存放排序后的数组
    vector<int> count(10, 0); // 计数器数组，大小为10，表示每个数字的出现频率

    // 统计每个数字在指定位上的出现频率
    for (int i = 0; i < n; ++i)
    {
        int d = getDigit(arr[i], digit);
        count[d]++;
    }

    // 计算累计频率
    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    // 根据计数器对数字进行排序
    for (int i = n - 1; i >= 0; --i)
    {
        int d = getDigit(arr[i], digit);
        output[count[d] - 1] = arr[i];
        count[d]--;
    }

    // 将排序后的数组复制回原数组
    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
}

// 基数排序主函数
void radixSort(vector<int> &arr)
{
    int n = arr.size();

    // 获取数组中最大的数字，以确定排序的次数
    int maxElem = *max_element(arr.begin(), arr.end());

    // 进行按位排序，直到最大的数字的位数
    for (int digit = 0; maxElem / static_cast<int>(pow(10, digit)) > 0; ++digit)
    {
        countingSort(arr, n, digit);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "原始数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "排序后的数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <iostream> //计数排序
#include <vector>
#include <algorithm>

using namespace std;

// 计数排序函数
void countingSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    // 找到数组中的最大值和最小值
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    // 创建计数数组，大小为 (maxVal - minVal + 1)
    vector<int> count(maxVal - minVal + 1, 0);

    // 统计每个元素的出现次数
    for (int num : arr)
    {
        count[num - minVal]++;
    }

    // 将计数数组中的元素按排序后的顺序写回原数组
    int index = 0;
    for (int i = 0; i < count.size(); ++i)
    {
        while (count[i] > 0)
        {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "原始数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "排序后的数组：";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
