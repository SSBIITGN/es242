#include "test.h"

#include <string.h> // for testing generate_splits()
#include <stdlib.h>
#include <stdio.h>
/*
 * Generate k-selections of a[0..n-1] in lexicographic order and call process_selection to process them.
 *
 * The array b[] will have enough space to hold k elements.
 * For a selection i1, ..., ik, you should set b[0] = a[i1], ..., b[k-1] = a[ik].
 * Selections should be generated in lexicographic order.
 * a[0..k-1] is the smallest selection and a[n-k..n-1] is the largest.
 */

void generate_selections(int a[], int n, int k, int b[], void *data, void (*process_selection)(int *b, int k, void *data)) {
    int *indices = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        indices[i] = i;
    }
    while (1) {
        for (int i = 0; i < k; i++) {
            b[i] = a[indices[i]];
        }
        process_selection(b, k, data);
        int i = k - 1;
        while (i >= 0 && indices[i] == n - k + i) {
            i--;
        }
        if (i < 0) {
            break;
        }
        indices[i]++;
        for (int j = i + 1; j < k; j++) {
            indices[j] = indices[j - 1] + 1;
        }
    }

    free(indices);
}
/*
 * See Exercise 2 (a), page 94 in Jeff Erickson's textbook.
 * The exercise only asks you to count the possible splits.
 * In this assignment, you have to generate all possible splits into buf[]
 * and call process_split() to process them.
 * The dictionary parameter is an array of words, sorted in dictionary order.
 * nwords is the number of words in this dictionary.
 */
int IsWord(const char *str, const char *dictionary[], int nwords) {
    for (int i = 0; i < nwords; i++) {
        if (strcmp(str, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0; 
}

void generate_splits_recursive(const char *source, const char *dictionary[], int nwords, char buf[], int buf_index, void *data, void (*process_split)(char buf[], void *data)) {
    int len = strlen(source);
    for (int i = 1; i <= len; i++) {
        strncpy(buf + buf_index, source, i);
        buf[buf_index + i] = '\0';

        if (IsWord(buf + buf_index, dictionary, nwords)) {
            if (i == len) {
                process_split(buf, data);
            } else {
                buf[buf_index + i] = ' '; 
                generate_splits_recursive(source + i, dictionary, nwords, buf, buf_index + i + 1, data, process_split);
            }
        }
    }
}

void generate_splits(const char *source, const char *dictionary[], int nwords, char buf[], void *data, void (*process_split)(char buf[], void *data)) {
    generate_splits_recursive(source, dictionary, nwords, buf, 0, data, process_split);
}

/*
 * Transform a[] so that it becomes the previous permutation of the elements in it.
 * If a[] is the first permutation, leave it unchanged.
 */

int lower_bound(int arr[],int k,int N,int X)
{   int ind=k;
    for (ind;ind<N;ind++){
        if (X<arr[ind]){
            break;
        }
    }
    return ind-1;
}
void previous_permutation(int a[], int n){
    int tempi;
    int temp;
    int ind;
    if (n!=1){
        for (int i=n-1;i>0;i--){
            if (a[i]<a[i-1]){
                tempi=lower_bound(a,i,n,a[i-1]);
                temp=a[tempi];
                a[tempi]=a[i-1];
                a[i-1]=temp;            
                ind=i;
                break;
            }

        }
        int k=1;
        for (int i=ind;i<(n+ind)/2;i++){
            temp=a[i];
            a[i]=a[n-k];
            a[n-k]=temp;
            k+=1;
        }
    }
}

/* Write your tests here. Use the previous assignment for reference. */

typedef struct {
    int index;
    int err;
} state_t;

static void test_selections_2165(int b[], int k, void *data)
{
    state_t *s = (state_t *)data;
    s->err = 0;
    switch (s->index) {
    case 0:
        if ((b[0] != 2) || (b[1] != 1)) {
            s->err = 1;
        }
        break;
    case 1:
        if ((b[0] != 2) || (b[1] != 6)) {
            s->err = 1;
        }
        break;
    case 2:
        if ((b[0] != 2) || (b[1] != 5)) {
            s->err = 1;
        }
        break;
    case 3:
        if ((b[0] != 1) || (b[1] != 6)) {
            s->err = 1;
        }
        break;
    case 4:
        if ((b[0] != 1) || (b[1] != 5)) {
            s->err = 1;
        }
        break;
    case 5:
        if ((b[0] != 6) || (b[1] != 5)) {
            s->err = 1;
        }
        break;
    default:
        s->err = 1;
    }
    ++(s->index);
}

BEGIN_TEST(generate_selections) {
    int a[] = { 2, 1, 6, 5 };
    int b[2];
    state_t s2165 = { .index = 0, .err = 1 };
    generate_selections(a, 4, 2, b, &s2165, test_selections_2165);
    ASSERT(!s2165.err, "Failed on 2 1 6 5.");
} END_TEST

void test_splits_art(char buf[], void *data)
{
    state_t *s = (state_t*)data;
    s->err = 0;
    switch (s->index) {
    case 0:
        if (!strcmp(buf, "art is toil")) {
            s->err = 1;
        }
        break;
    case 1:
        if (!strcmp(buf, "artist oil")) {
            s->err = 1;
        }
        break;
    default:
        s->err = 1;
    }
}

BEGIN_TEST(generate_splits) {
    const char *a = "artistoil";
    const char *dict[] = {
        "art",
        "artist",
        "is",
        "oil",
        "toil"
    };
    int nwords = 5;
    state_t s = { .index = 0, .err = 1 };
    char buf[256];
    generate_splits(a, dict, nwords, buf, &s, test_splits_art);
    ASSERT(!s.err, "Failed on 'artistoil'.");
} END_TEST

BEGIN_TEST(previous_permutation) {
    int a[] = {1,5,6,2,3,4};
    previous_permutation(a, 6);
    
    ASSERT_ARRAY_VALUES_EQ(a, 6, "Failed on 1 5 6 2 3 4.", 1, 5, 4, 6, 3, 2);
} END_TEST

int main()
{
    run_tests((test_t[]) {
            TEST(generate_selections),
            TEST(generate_splits),
            TEST(previous_permutation),
            0
        });
    return 0;
}
