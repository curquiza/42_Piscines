SELECT etage_salle as 'etage', sum(nbr_siege) as 'sieges'
FROM salle
GROUP BY etage
ORDER BY sum(nbr_siege) DESC;
