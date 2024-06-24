typedef struct {
    int n;
} FooBar;

int flag = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&mtx);
        if(flag == 1) {
            pthread_cond_wait(&cond, &mtx);
        }
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        flag = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&mtx);
        if(flag == 0) {
            pthread_cond_wait(&cond, &mtx);
        }
        // printBar() outputs "bar". Do not change or remove this line.
        // pthread_mutex_lock(&mtx);
        printBar();
        flag = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);
    }
}

void fooBarFree(FooBar* obj) {
    free(obj);
}
