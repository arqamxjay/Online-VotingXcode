//  main.c
//  Online Voting
//
//  Created by Arqam´s on 1/20/26.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VOTER_FILE "voters.dat"
#define VOTE_FILE  "votes.dat"

/*
   Simple Online Voting System (Local Simulation)
   - Authentication through Voter ID + Password
   - One vote per voter
   - File based storage
   - Human written, rule based logic
*/
/* ---------- STRUCTURES ---------- */
struct Voter {
    int id;
    char password[20];
    int hasVoted;   // 0 = not voted, 1 = voted
};

struct VoteCount {
    int candidate1;
    int candidate2;
    int candidate3;
};
/* ---------- INITIAL SETUP ---------- */
void initializeFiles() {
    FILE *f;

    // Create voters file if not exists
    f = fopen(VOTER_FILE, "r");
    if (f == NULL) {
        f = fopen(VOTER_FILE, "w");
        struct Voter v1 = {101, "alpha", 0};
        struct Voter v2 = {102, "beta", 0};
        struct Voter v3 = {103, "gamma", 0};
        fwrite(&v1, sizeof(struct Voter), 1, f);
        fwrite(&v2, sizeof(struct Voter), 1, f);
        fwrite(&v3, sizeof(struct Voter), 1, f);
        fclose(f);
    } else {
        fclose(f);
    }
    // Create vote file if not exists
    f = fopen(VOTE_FILE, "r");
    if (f == NULL) {
        f = fopen(VOTE_FILE, "w");
        struct VoteCount vc = {0, 0, 0};
        fwrite(&vc, sizeof(struct VoteCount), 1, f);
        fclose(f);
    } else {
        fclose(f);
    }
}
/* ---------- AUTHENTICATION ---------- */
int authenticate(int id, char password[]) {
    FILE *f = fopen(VOTER_FILE, "r");
    struct Voter v;

    while (fread(&v, sizeof(struct Voter), 1, f)) {
        if (v.id == id && strcmp(v.password, password) == 0) {
            fclose(f);
            return 1; // authenticated
        }
    }
    fclose(f);
    return 0;
}
/* ---------- CHECK IF ALREADY VOTED ---------- */
int hasAlreadyVoted(int id) {
    FILE *f = fopen(VOTER_FILE, "r");
    struct Voter v;

    while (fread(&v, sizeof(struct Voter), 1, f)) {
        if (v.id == id) {
            fclose(f);
            return v.hasVoted;
        }
    }
    fclose(f);
    return 1;
}
/* ---------- MARK VOTER AS VOTED ---------- */
void markAsVoted(int id) {
    FILE *f = fopen(VOTER_FILE, "r+");
    struct Voter v;

    while (fread(&v, sizeof(struct Voter), 1, f)) {
        if (v.id == id) {
            v.hasVoted = 1;
            fseek(f, -sizeof(struct Voter), SEEK_CUR);
            fwrite(&v, sizeof(struct Voter), 1, f);
            break;
        }
    }
    fclose(f);
}
/* ---------- CAST VOTE ---------- */
void castVote(int choice) {
    FILE *f = fopen(VOTE_FILE, "r+");
    struct VoteCount vc;

    fread(&vc, sizeof(struct VoteCount), 1, f);

    if (choice == 1) vc.candidate1++;
    else if (choice == 2) vc.candidate2++;
    else if (choice == 3) vc.candidate3++;

    fseek(f, 0, SEEK_SET);
    fwrite(&vc, sizeof(struct VoteCount), 1, f);

    fclose(f);
}
/* ---------- DISPLAY RESULTS ---------- */
void showResults() {
    FILE *f = fopen(VOTE_FILE, "r");
    struct VoteCount vc;

    fread(&vc, sizeof(struct VoteCount), 1, f);

    printf("\n===== Election Results =====\n");
    printf("Candidate 1: %d votes\n", vc.candidate1);
    printf("Candidate 2: %d votes\n", vc.candidate2);
    printf("Candidate 3: %d votes\n", vc.candidate3);

    fclose(f);
}
/* ---------- MAIN MENU ---------- */
int main() {
    int id, choice;
    char password[20];

    initializeFiles();

    printf("=====================================\n");
    printf("   Online Voting System (Simulation)\n");
    printf("=====================================\n");

    printf("Enter Voter ID: ");
    scanf("%d", &id);

    printf("Enter Password: ");
    scanf("%s", password);

    if (!authenticate(id, password)) {
        printf("Authentication Failed!\n");
        return 0;
    }

    if (hasAlreadyVoted(id)) {
        printf("You have already voted. Multiple voting is not allowed.\n");
        return 0;
    }

    printf("\nCandidates List:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");

    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        return 0;
    }

    castVote(choice);
    markAsVoted(id);

    printf("\nVote successfully cast!\n");
    showResults();

    return 0;
}
