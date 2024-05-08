#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义分区信息结构体
typedef struct {
    char partition_name[30];
    int value;
} Partition;

// 模拟数据库中的分区表创建
void create_partition_table(const char *table_name, const char *partition_key, Partition partitions[], int partition_count) {
    printf("Creating table '%s' with partitioning by '%s'\n", table_name, partition_key);
    for (int i = 0; i < partition_count; ++i) {
        printf("    partition %s values less than (%d)\n", partitions[i].partition_name, partitions[i].value);
    }
}

int main() {
    // 定义分区信息数组
    Partition partitions[] = {
        {"range_pt_p1", 10},
        {"range_pt_p2", 20},
        {"range_pt_p3", 40},
        {"range_pt_p4", 80},
        {"range_pt_p5", 100}
    };
    int partition_count = sizeof(partitions) / sizeof(partitions[0]);

    // 模拟创建分区表
    create_partition_table("range_pt", "age", partitions, partition_count);

    return 0;
}