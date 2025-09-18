#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Définition d'une structure pour stocker les statistiques du CPU
typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} CpuStats;

// Fonction pour lire les statistiques du CPU depuis le fichier virtuel /proc/stat
void read_cpu_stats(CpuStats *stats) {
    // Tente d'ouvrir le fichier en lecture
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        // Affiche une erreur si l'ouverture échoue
        perror("Impossible d'ouvrir /proc/stat");
        exit(1);
    }
// Lit les valeurs des différentes statistiques du CPU
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
           &stats->user, &stats->nice, &stats->system, &stats->idle,
           &stats->iowait, &stats->irq, &stats->softirq, &stats->steal,
           &stats->guest, &stats->guest_nice);
    // Ferme le fichier
    fclose(fp);
}

int main() {
    CpuStats stats1, stats2;
    unsigned long long total_jiffies1, idle_jiffies1;
    unsigned long long total_jiffies2, idle_jiffies2;
    
    // Première lecture des statistiques pour l'état initial
    read_cpu_stats(&stats1);
    // Calcule le total des "jiffies" (unités de temps du CPU)
    total_jiffies1 = stats1.user + stats1.nice + stats1.system + stats1.idle +
                     stats1.iowait + stats1.irq + stats1.softirq + stats1.steal;
    // Stocke les "jiffies" d'inactivité
    idle_jiffies1 = stats1.idle;

    // Met le programme en pause pendant 1 seconde
    sleep(1);

    // Deuxième lecture des statistiques après 1 seconde
    read_cpu_stats(&stats2);
// Calcule le nouveau total des "jiffies"
    total_jiffies2 = stats2.user + stats2.nice + stats2.system + stats2.idle +
                     stats2.iowait + stats2.irq + stats2.softirq + stats2.steal;
    // Stocke les nouveaux "jiffies" d'inactivité
    idle_jiffies2 = stats2.idle;

    // Calcule la différence pour trouver les "jiffies" consommés et d'inactivité pendant la période
    unsigned long long total_diff = total_jiffies2 - total_jiffies1;
    unsigned long long idle_diff = idle_jiffies2 - idle_jiffies1;

    // Calcule l'utilisation du CPU en pourcentage
    double cpu_usage = 100.0 * (1.0 - (double)idle_diff / total_diff);

    // Affiche le résultat formaté
    printf("Utilisation du CPU : %.2f%%\n", cpu_usage);

    return 0;
}
