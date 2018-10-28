SELECT count(id_abo) as 'nb_abo', floor(avg(prix)) as 'moy_abo', sum(duree_abo) % 42 as 'ft'
FROM abonnement;
