#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h> // 必须包含此头文件以使用 intptr_t

void *mythread(void *arg)
{
    // 将传入的指针安全地转换回整数
    intptr_t a = (intptr_t)arg;
    printf("%ld\n", a);
    // 将计算结果安全地转换回指针并返回
    return (void *)(a + 1);
}

int main(int argc, char *argv[])
{
    pthread_t p;
    void *retval; // 用一个 void* 指针来接收返回值

    pthread_create(&p, NULL, mythread, (void *)100);
    pthread_join(p, &retval); // 将 retval 的地址传给 pthread_join

    // 将接收到的指针安全地转换回整数
    int m = (intptr_t)retval;

    printf("returned: %d\n", m);
    return 0;
}
int add()

    /*
    void *mythread(void *arg)
    {
        int a = (int)arg;
        printf("%d\n", a);
        return (void *)(arg + 1);
    }

    int main(int argc, char *argv[])
    {
        pthread_t p;
        int rc, m;
        pthread_create(&p, NULL, mythread, (void *)100);
        pthread_join(p, (void **)&m);
        printf("returned: %d", m);
        return 0;
    }
    */
    /*
    #include <stdio.h>
    #include <pthread.h>
    #include <stdint.h>

    void *mythread(void *arg)
    {
        intptr_t a = (intptr_t)arg;
        printf("%ld\n", a);
        return (void *)(a + 1);
    }

    int main()
    {
        pthread_t p;
        void *ret;

        pthread_create(&p, NULL, mythread, (void *)(intptr_t)100);
        pthread_join(p, &ret);

        printf("returned: %ld\n", (intptr_t)ret);
        return 0;
    }
    */