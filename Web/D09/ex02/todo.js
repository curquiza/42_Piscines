function ft_load_cookies() {
	var tab = document.cookie.split(';');
	for (var i = 0; i < tab.length; i++) {
		tab[i] = tab[i].trim();
		start = tab[i].indexOf('=');
		var cookie_name = tab[i].substr(0, start);
		var todo_recup = tab[i].substr(start + 1);
		if (ft_check_cookie_name(cookie_name) == true)
			ft_add_div(todo_recup, cookie_name);
	}
}        
function ft_check_cookie_name(name) {
	if (name.substr(0, 9) != 'd09_ex02_')
		return false;
	var nbr = name.substr(9);
	if (isNaN(+nbr) == true || nbr == "")
		return false;
	return true;
}

function ft_add_div(str, id) {
	todo = document.createTextNode(str);
	var div = document.getElementById("ft_list");
	var new_div = document.createElement('div');
	new_div.setAttribute('class', 'todo');
	new_div.setAttribute('id', id);
	new_div.setAttribute('onclick', 'ft_supp(this)');
	new_div.appendChild(todo);
	div.insertBefore(new_div, div.firstChild);
}

function ft_add() {
	var todo_recup = prompt("What do you want to do ?");
	if (todo_recup != null && todo_recup != "") {
		ft_add_div(todo_recup, 'd09_ex02_' + ft_get_cookie_number());

		var expires = "expires=Wed, 19 Jul 2017 00:00:00 UTC";
		var name = 'd09_ex02_' + ft_get_cookie_number();
		document.cookie = name + "=" + todo_recup + " ;" + expires;           
	}

}

function ft_get_cookie_number() {
	var nbr = 0;
	var tmp = 0;
	var tab = document.cookie.split(';');
	for (var i = 0; i < tab.length; i++) {
		tab[i] = tab[i].trim();
		start = tab[i].indexOf('=');
		tmp = 0;
		var cookie_name = tab[i].substr(0, start);
		if (ft_check_cookie_name(cookie_name) == true) {
			tmp = cookie_name.substr(9);
			if (+tmp > +nbr)
				nbr = +tmp;
		}
	}
	return (+nbr + 1);
}

function ft_supp(elem) {
	if (confirm("Are you very sure you want to remove your task ?")) {
		document.cookie = elem.id + "= ;expires= 1 Jan 1970 00:00:00 GMT;";
		var div = document.getElementById("ft_list");
		div.removeChild(elem);
	}
}
