#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define STUDENTS 10
#define LOBBY_CHAIRS 3

pthread_mutex_t mutex;
sem_t sem_students, sem_tutor;

int seats = 0;
int total_served = 0;

void* tutor(void* arg) {
    while (1) {
        sem_wait(&sem_students);

        pthread_mutex_lock(&mutex);
        if (total_served >= STUDENTS) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        seats--;
        printf("Consultation begins for a waiting student\n");
        printf("Seats now available in lobby: %d\n", LOBBY_CHAIRS - seats);
        pthread_mutex_unlock(&mutex);

        sem_post(&sem_tutor);
        sleep(1);
    }

    pthread_exit(NULL);
}

void* student(void* arg) {
    int student_id = ((int)arg);
    free(arg);

    usleep((rand() % 2000 + 1000) * 1000);

    pthread_mutex_lock(&mutex);
    if (seats < LOBBY_CHAIRS) {
        seats++;
        printf("Student %d enters lobby and waits\n", student_id);
        sem_post(&sem_students);
        pthread_mutex_unlock(&mutex);

        sem_wait(&sem_tutor);
        printf("Student %d is in consultation\n", student_id);
        sleep(1);
        printf("Student %d has completed consultation\n", student_id);

        pthread_mutex_lock(&mutex);
        total_served++;
        pthread_mutex_unlock(&mutex);
    } else {
        printf("Lobby full. Student %d leaves without consultation\n", student_id);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t tutor_thread, student_threads[STUDENTS];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem_students, 0, 0);
    sem_init(&sem_tutor, 0, 0);

    pthread_create(&tutor_thread, NULL, tutor, NULL);

    for (int i = 0; i < STUDENTS; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&student_threads[i], NULL, student, id);
    }

    for (int i = 0; i < STUDENTS; i++) {
        pthread_join(student_threads[i], NULL);
    }

    pthread_mutex_lock(&mutex);
    sem_post(&sem_students);
    pthread_mutex_unlock(&mutex);

    pthread_join(tutor_thread, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem_students);
    sem_destroy(&sem_tutor);

    return 0;
}