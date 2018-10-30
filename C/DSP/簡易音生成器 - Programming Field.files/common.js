/* あ */

/**
 * @type {function (): any}
 */
var GetQueryString;
/**
 * @type {function (string): any}
 */
var ParseQueryStringEx;
/**
 * (no leading '?' character)
 * @type {function (any): string}
 */
var GenerateQueryString;
/**
 * @param {HTMLElement} elem
 * @param {string} className
 */
function AddCSSClass(elem, className) {
	if (elem.classList)
		elem.classList.add(className);
	else if (!(new RegExp("\\b" + className + "\\b")).test(elem.className))
		elem.className += " " + className;
}
/**
 * @param {HTMLElement} elem
 * @param {string} className
 */
function RemoveCSSClass(elem, className) {
	if (elem.classList)
		elem.classList.remove(className);
	else if (elem.className)
		elem.className = elem.className.replace(new RegExp("\\b" + className + "\\b"), "");
}
/**
 * @param {HTMLElement} elem
 * @param {string} className
 * @return {boolean}
 */
function HasCSSClass(elem, className) {
	if (elem.classList)
		return elem.classList.contains(className);
	else
		return (new RegExp("\\b" + className + "\\b")).test(elem.className);
}

(function() {

if (!Array.prototype.push) {
	Array.prototype.push = function push(obj) { this[this.length++] = obj; };
}

if (!Array.prototype.forEach) {
	Array.prototype.forEach = function (fn) {
		var a = []; a.length = this.length;
		for (var i = 0; i < a.length; ++i) {
			a[i] = this[i];
		}
		for (var i = 0; i < a.length; ++i) {
			fn(a[i]);
		}
	};
}

if (!Array.forEach) {
	Array.forEach = function (arr, fn) {
		arr.forEach(fn);
	};
}

if (!Object.keys) {
	Object.keys = function (obj) {
		var a = [];
		for (var k in obj)
			a.push(k);
		return a;
	};
}

var enc = function (s) { return s.toString(); };
var dec = function (s) { return s.toString(); };
if (typeof(window) !== 'undefined') {
	enc = window.encodeURIComponent || window.escape;
	dec = window.decodeURIComponent || window.unescape;
}
var cloneObject = function (obj) {
	var r = {};
	for (var k in obj) { r[k] = obj[k]; }
	return r;
};

ParseQueryStringEx = function (s) {
	if (!s) {
		return {};
	}
	var ret = {};
	var vals = s.split('&');
	vals.forEach(function (e) {
		if (/^(.*?)=(.*)$/.test(e)) {
			ret[dec(RegExp.$1)] = dec(RegExp.$2);
		}
	});
	return ret;
};

var _tempQS = {};
var _tempLS = null;
GetQueryString = function () {
	if (typeof(location) !== 'undefined') {
		var ls = location.search.substring(1);
		if (_tempLS == ls) {
			return cloneObject(_tempQS);
		}
		_tempLS = ls;
	}
	if (_tempLS !== null) {
		_tempQS = ParseQueryStringEx(_tempLS);
	}
	return cloneObject(_tempQS);
};

GenerateQueryString = function (obj) {
	var s = '';
	if (obj) {
		for (var k in obj) {
			if (s !== '') {
				s += '&';
			}
			s += enc(k) + '=' + enc(obj[k]);
		}
	}
	return s;
};

})();

//
(function () {
	function getClickExpandListener(parentElement) {
		var expanded = false;
		return function (e) {
			if (!expanded) {
				expanded = true;
				parentElement.classList.add('expanded');
			}
			if (e)
				e.preventDefault();
			return false;
		};
	}

	function onLoad() {
		if (!document.getElementsByTagName)
			return;
		var a = document.getElementsByTagName('header');
		for (var i = 0, len = a.length; i < len; ++i) {
			var aa = a[i].getElementsByTagName('nav');
			if (aa)
				aa = aa[0].getElementsByTagName('ul');
			if (aa.length) {
				var e = aa[0];
				var firstLi = null;
				var c = e.firstChild;
				while (c) {
					if (c.nodeType === 1 && c.tagName.toLowerCase() === 'li') {
						firstLi = c;
						break;
					}
					c = c.nextSibling;
				}

				c = e.lastChild;
				var x = 0;
				var lastCollapsed = null;
				while (c) {
					if (c.nodeType === 1 && c.tagName.toLowerCase() === 'li') {
						if (c === firstLi) {
							var ref = c.getElementsByTagName('a')[0];
							if (!ref) {
								ref = c;
							}
							if (ref.textContent) {
								ref.textContent = 'Top';
							} else {
								while (ref.firstChild) {
									ref.removeChild(ref.firstChild);
								}
								ref.appendChild(document.createTextNode('Top'));
							}
							if (lastCollapsed) {
								var fn = getClickExpandListener(e);
								var expandElement = document.createElement('li');
								expandElement.className = 'expand';
								var v = document.createElement('a');
								v.href = '';
								v.onclick = fn;
								v.appendChild(document.createTextNode('...'));
								expandElement.appendChild(v);
								if (c.nextSibling) {
									e.insertBefore(expandElement, c.nextSibling);
								} else {
									e.appendChild(expandElement);
								}
								window.setTimeout(function () {
									var s = window.getComputedStyle && window.getComputedStyle(lastCollapsed, '');
									if (s) {
										if (s.display !== 'none') {
											expandElement.removeChild(v);
											fn();
										}
									}
								}, 0);
							}
						} else {
							if (x >= 2) {
								c.classList.add('collapsed');
								lastCollapsed = c;
							}
						}
						++x;
					}
					c = c.previousSibling;
				}
				break;
			}
		}
	}
	if (document.addEventListener) {
		document.addEventListener('DOMContentLoaded', onLoad, false);
	} else if (window.attachEvent) {
		window.attachEvent('onload', onLoad);
	} else {
		window.onload = (function () {
			var fn = window.onload;
			return function () { onLoad(); return fn ? fn.apply(this, arguments) : void(0); }
		})();
	}
})();
