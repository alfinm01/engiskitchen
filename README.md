# engiskitchen
Tugas Besar Algoritma dan Struktur Data

## TIPS
Download Github (bisa versi Github Desktop (ada UI-nya) atau versi CLI (dioperasiin di cmd))

## Cara pake Github (versi CLI (Command Line Interface)):

### Konfigurasi Github
1. Download & install Github
    Untuk versi Windows, bisa dari sini https://gitforwindows.org/
    Untuk versi Linux / Mac, bisa dilihat di sini https://gist.github.com/derhuerst/1b15ff4652a867391f03
2. Bikin akun Github
3. Login di Git Bash (via CLI)
    Ketik (dan ganti username & email):
      git config --global user.name "John Doe"
      git config --global user.email johndoe@example.com
4. Cek konfigurasi:
    git config --list

### Operasiin Github
1. Masuk ke directory (folder) di mana kalian mau nyimpen file-file nya di PC masing-masing
    Contoh: D:\Coding\C\Alstrukdat
2. Cloning dari repo ini
    git clone https://github.com/alfinm01/engiskitchen.git
3. Sekarang tinggal ngoding-ngoding seperti biasa
4. Sebelum ngoding, operasiin ini dulu:
    git pull                        -> Buat ngambil perubahan terbaru yang belum kita ambil dari repo
5. Kalo udah ada perubahan:
    git add .                       -> Buat nge-add semua file yang udah kita ubah
    git commit -m "pesan"           -> Buat merekam perubahan dari repo (pesannya diganti yang sesuai, misal: perubahan di fungsi..., dll)
    git push origin master          -> Upload commit-commit yang udah kita buat (bisa berkali-kali commit baru sekali push) ke repo online
6. Fitur-fitur lain:
    git status                      -> Ngelihat status git
    git diff                        -> Ngelihat perbedaan dari yang di PC kita dengan yang di repo
    git checkout                    -> Nge-undo perubahan (?)
    
## Note: Cara-cara ini masih banyak khilafnya dan belum sempurna, buat lengkapnya bisa browsing sendiri atau tanya-tanya aja
