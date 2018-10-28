SELECT upper(perso.nom) as 'NOM', perso.prenom, abo.prix
FROM abonnement as abo, membre as m, fiche_personne as perso
WHERE abo.id_abo = m.id_abo AND abo.prix > 42 AND m.id_fiche_perso = perso.id_perso
ORDER BY perso.nom, perso.prenom ASC;
