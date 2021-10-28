//operations
L* createlist(int arr[], int size);
int insert(L* list, N* node);
N* search(L* list, int k);
N* delete(L* list, N* node);
int isEmpty(L* list);
N* successor(L* list, N* node);
N* predecessor(L* list, N* node);
N* maximum(L* list);
N* minimum(L* list);

//tests
void testDelete(L* list, int key);
int testMax(L* list, int key);
int testMin(L* list, int key);
int testSucc(L* list, int key);
int testPre(L* list, int key);
int testPreMax(L* list1, L* list2);
