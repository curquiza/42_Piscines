CREATE TABLE ft_table (
	id INT NOT NULL AUTO_INCREMENT,
	login varchar(8) DEFAULT 'toto' NOT NULL,
	groupe enum('staff', 'student', 'other') NOT NULL,
	date_de_creation date NOT NULL,
	PRIMARY KEY(id)
);
