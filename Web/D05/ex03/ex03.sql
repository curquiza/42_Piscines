INSERT INTO ft_table (login, groupe, date_de_creation)
SELECT nom, "other", date_naissance FROM fiche_personne
WHERE length(nom) <= 8 AND instr(nom, "a") != 0 ORDER BY nom LIMIT 10;
