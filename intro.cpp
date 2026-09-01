//
//  intro.cpp
//  dasarPemrograman_CPP
//
//  Created by Al-Ghani Desta Setyawan on 31/08/26.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Data pribadi saya
    string nama = "Al-Ghani Desta Setyawan";
    string lokasi = "Samarinda, East Kalimantan, Indonesia";
    string status = "Mahasiswa S1 (Teknik Informatika / bidang terkait)";
    string latar_belakang = "Lulusan SMK (Vocational High School)";

    // Minat & keahlian saya
    string minat_utama[] = {
        "Software development & web app projects",
        "Audiophile audio equipment",
        "Health & wellness (skincare, vitamins, reflexology)",
        "K-pop & music culture",
        "Education & teaching materials"
    };

    string teknologi_preferensi[] = {
        "Linux/Ubuntu server environments",
        "Windows OS",
        "Web frameworks: Vite, React, Ionic",
        "AI agents & automation workflows",
        "Open-source projects"
    };

    string bahasa_pemrograman[] = {
        "JavaScript / TypeScript (React, Ionic)",
        "Shell commands & Linux environment",
        "Tertarik belajar Swift"
    };

    // Tampilan intro
    cout << "========================================\n";
    cout << "           INTRO DIRI - AL-GHANI        \n";
    cout << "========================================\n\n";

    cout << "Nama              : " << nama << "\n";
    cout << "Lokasi            : " << lokasi << "\n";
    cout << "Status            : " << status << "\n";
    cout << "Latar Belakang    : " << latar_belakang << "\n\n";

    cout << "Minat Utama:\n";
    for (int i = 0; i < 5; i++) {
        cout << "  - " << minat_utama[i] << "\n";
    }
    cout << "\n";

    cout << "Teknologi Preferensi:\n";
    for (int i = 0; i < 5; i++) {
        cout << "  - " << teknologi_preferensi[i] << "\n";
    }
    cout << "\n";

    cout << "Bahasa Pemrograman:\n";
    for (int i = 0; i < 3; i++) {
        cout << "  - " << bahasa_pemrograman[i] << "\n";
    }
    cout << "\n";

    cout << "========================================\n";
    cout << "      Tech-savvy undergrad from ID      \n";
    cout << "========================================\n";

    return 0;
}
