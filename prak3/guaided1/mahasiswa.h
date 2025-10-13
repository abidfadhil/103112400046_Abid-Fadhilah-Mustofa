#ifindef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    char nim[10]
    int nilai1, nilai2
};

vold inputMhs(mahasiswa&m);
float rata2(mahasiswa m);

#endif