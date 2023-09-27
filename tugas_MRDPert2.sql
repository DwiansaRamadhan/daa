CREATE TABLE `fakultas`  (
  `id` int(11) NOT NULL,
  `nama` varchar(255) NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `kampus`  (
  `id` int(11) NOT NULL,
  `nama` varchar(255) NULL,
  `kode` varchar(255) NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `lulus`  (
  `id` int(11) NOT NULL,
  `status_lulus` char(5) NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `mahasiswa`  (
  `id` int(11) NOT NULL,
  `nim` varchar(255) NULL,
  `nama` varchar(255) NULL,
  `umur` int(3) NULL,
  `nama_ayah` varchar(255) NULL,
  `nama_ibu` varchar(255) NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `mata_kuliah`  (
  `id` int(11) NOT NULL,
  `nama` varchar(255) NULL,
  `kode` varchar(255) NULL,
  PRIMARY KEY (`id`)
);

CREATE TABLE `nilai`  (
  `id` int(11) NOT NULL,
  `ipk` float(5) NULL,
  `ips` float(5) NULL,
  `nilai` int(5) NULL,
  `bobot` decimal(3) NULL,
  PRIMARY KEY (`id`)
);

ALTER TABLE `kampus` ADD CONSTRAINT `fk_kampus_fakultas_1` FOREIGN KEY (`id`) REFERENCES `fakultas` (`id`);
ALTER TABLE `lulus` ADD CONSTRAINT `fk_lulus_nilai_1` FOREIGN KEY (`id`) REFERENCES `nilai` (`id`);
ALTER TABLE `mahasiswa` ADD CONSTRAINT `fk_mahasiswa_nilai_1` FOREIGN KEY (`id`) REFERENCES `nilai` (`id`);
ALTER TABLE `mahasiswa` ADD CONSTRAINT `fk_mahasiswa_fakultas_1` FOREIGN KEY (`id`) REFERENCES `fakultas` (`id`);
ALTER TABLE `mata_kuliah` ADD CONSTRAINT `fk_mata_kuliah_fakultas_1` FOREIGN KEY (`id`) REFERENCES `fakultas` (`id`);

