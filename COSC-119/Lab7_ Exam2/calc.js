var report = function (display) {
	document.getElementById("result").innerHTML =
	display;
};

document.getElementById("add").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	var r = parseFloat(document.getElementById("right").value);

	report(l + r);
};

document.getElementById("subtract").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	var r = parseFloat(document.getElementById("right").value);

	report(l - r);
};

document.getElementById("multiply").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	var r = parseFloat(document.getElementById("right").value);

	report(l * r);
};

document.getElementById("divide").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	var r = parseFloat(document.getElementById("right").value);

	report(l / r);
};

document.getElementById("modulo").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	var r = parseFloat(document.getElementById("right").value);

	report(l % r);
};

document.getElementById("raise").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	var r = parseFloat(document.getElementById("right").value);
	var x = l;
	
	for(var i = 1; i < r; i++){
		x*=l;
	}

	report(x);
};

document.getElementById("sum").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	var r = parseFloat(document.getElementById("right").value);
	
	if(l > r){
		var temp = l;
		l = r;
		r = temp;
	}
	
	var x = l;
	for(var i = l + 1; i <= r; i++){
		x+=i;
	}	
	
	report(x);
};

document.getElementById("root").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);

	report(Math.sqrt(l));
};

document.getElementById("negate").onclick = function () {
	var l = parseFloat(document.getElementById("left").value);
	
	if(l){
		report(false);
	} else {
		report(true);
	}
	
};