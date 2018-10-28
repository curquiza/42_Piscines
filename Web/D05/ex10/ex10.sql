SELECT f.titre as 'Titre', f.resum as 'Resume', f.annee_prod
FROM film as f, genre as g
WHERE f.id_genre = g.id_genre AND g.nom = 'erotic'
ORDER BY annee_prod DESC;
