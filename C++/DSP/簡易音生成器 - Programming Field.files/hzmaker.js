/* あ */

var preInitialize = null;
var getFunctionFromEval = null;
var setErrorMessage = null;

(function () {
	var toRad = function (value) { return 2 * value * Math.PI; };
	var sin = Math.sin;
	var cos = Math.cos;
	getFunctionFromEval = function (code) {
		var fn;
		try {
			fn = eval('(function (value) { "use strict"; var fn,code,preInitialize,getFunctionFromEval,alert,confirm,prompt,window,location,document,console; var v = value, val = value, t = value; return ' + code + ';})');
		} catch (e) {
			console.log(e);
			return null;
		}
		return function (value) {
			try {
				var v = fn(value);
				return typeof(v) === typeof(fn) ? v(value) : v;
			} catch (e) {
				setErrorMessage(e);
				return NaN;
			}
		};
	};
})();

(function () {

/**
 * @typedef {{hz: number, func: (t:number)=>number, playData: PF.Wave.PlayContext}} NoteDataObject
 */

/**
 * @typedef {{element: HTMLElement, data: NoteDataObject}} NoteItemObject;
 */

/**
 * @type {PF.Wave.IWaveOutput}
 */
var output = null;

var ErrorMessageElement = null;
var NoteList = null;
var NoteItemHtml = '';
var NoteItemCountElement = null;
var NoteItemLastValuesElement = null;
/**
 * @type {NoteItemObject[]}
 */
var NoteItems = [];
/**
 * @type {NoteDataObject[]}
 */
var NoteItemValues = [];

var _addEventListenerForId = function (id, name, fn, options) {
	var e = document.getElementById(id);
	if (!e)
		return;
	return e.addEventListener(name, fn, options);
};

var _addEventListenerForClassFirst = function (parent, className, name, fn, options) {
	var elems = parent.getElementsByClassName(className);
	if (!elems || !elems.length)
		return;
	return elems[0].addEventListener(name, fn, options);
};

var getSelectElementSelectedValue = function (selectElement) {
	var i = selectElement.selectedIndex;
	if (i < 0 || i >= selectElement.options.length)
		return null;
	return selectElement.options[i].value;
};
var getSelectElementSelectedValueFromClassName = function (parent, className) {
	var elems = parent.getElementsByClassName(className);
	if (!elems || !elems.length)
		return;
	return getSelectElementSelectedValue(elems[0]);
};

var getValueFromClassName = function (parent, className) {
	var elems = parent.getElementsByClassName(className);
	if (!elems || !elems.length)
		return;
	return elems[0].value;
};
var setValueFromClassName = function (parent, className, value) {
	var elems = parent.getElementsByClassName(className);
	if (!elems || !elems.length)
		return;
	elems[0].value = value;
};

var setInnerTextForElement = function (elem, text) {
	while (elem.firstChild)
		elem.removeChild(elem.firstChild);
	elem.appendChild(document.createTextNode(text));
};

var setInnerTextForElementId = function (elemId, text) {
	var e = document.getElementById(elemId);
	e && setInnerTextForElement(e, text);
};


var _setErrorMessage = function (msg) {
	setInnerTextForElement(ErrorMessageElement, msg);
};
setErrorMessage = _setErrorMessage;


var PredefinedFunctions = {
	'sine': PF.Wave.sineWaveFunc,
	'square': PF.Wave.squareWaveFunc,
	'triangle': PF.Wave.triangleWaveFunc,
	'sawtooth': PF.Wave.sawtoothWaveFunc
};
var UserDefinedFunctions = {
};
var getHzFunction = function (value) {
	if (!value)
		return PF.Wave.sineWaveFunc;
	var f = PredefinedFunctions[value];
	if (f)
		return f;
	f = UserDefinedFunctions[value];
	if (f)
		return f;
	f = getFunctionFromEval(value);
	if (f) {
		UserDefinedFunctions[value] = f;
		return f;
	}
	return PF.Wave.sineWaveFunc;
};

var JustIntonationFunctions = [
	/*  0 */ function (v) { return v; },
	/*  1 */ function (v) { return v * 25 / 24; }, // ! (do+)
	/*  2 */ function (v) { return v * 9 / 8; },
	/*  3 */ function (v) { return v * 6 / 5; },   // ! (mi-)
	/*  4 */ function (v) { return v * 5 / 4; },
	/*  5 */ function (v) { return v * 4 / 3; },
	/*  6 */ function (v) { return v * 45 / 32; }, // ! (cf. 11 / 8)
	/*  7 */ function (v) { return v * 3 / 2; },
	/*  8 */ function (v) { return v * 25 / 16; }, // !
	/*  9 */ function (v) { return v * 5 / 3; },
	/* 10 */ function (v) { return v * 21 / 12; }, // !
	/* 11 */ function (v) { return v * 15 / 8; }
];

var updateLastValues = function () {
	NoteItemLastValuesElement.value = NoteItemValues.join("\n");
	NoteItemCountElement.value = NoteItemValues.length;
};
var removeNoteObject = function (o) {
	for (var i = NoteItemValues.length - 1; i >= 0; --i) {
		if (NoteItemValues[i] === o) {
			NoteItemValues.splice(i, 1);
			updateLastValues();
			return;
		}
	}
};

var isNoteItemElement = function (e) {
	return (e && e.tagName && e.tagName.toUpperCase() == 'LI' && e.className && e.className === 'noteItem');
};

/**
 * @param {NoteItemObject} item
 */
var playNoteItem = function (item) {
	var hz = getValueFromClassName(item.element, 'noteItemValue') || 440;
	var fn = getHzFunction(getValueFromClassName(item.element, 'noteFunction'));
	if (!output)
		output = PF.Wave.createWaveOutput();
	var buff = output.createWaveSource(hz, fn);
	var o = output.playWaveSource(buff, 2, function () { });
	item.data.playData = o;
	return o;
};

/**
 * @param {NoteItemObject} item
 */
var getNoteItemRemoveHandler = function (item) {
	return function () {
		removeNote(item);
	};
};

/**
 * @param {NoteItemObject} item
 */
var getNoteItemPlaySingleHandler = function (item) {
	return function () {
		_setErrorMessage('');
		var o = item.data;
		if (!o)
			return;
		if (o.playData && output.isPlayingContext(o.playData)) {
			output.stopContext(o.playData);
			o.playData = null;
		} else {
			playNoteItem(item);
		}
	};
};

var getPlayAllHandler = function () {
	return function () {
		_setErrorMessage('');
		var isAnyPlaying = false;
		Array.prototype.forEach.call(NoteList.childNodes, function (e) {
			var item = getNoteItemData(e);
			if (item) {
				var o = item.data;
				if (o && o.playData && output.isPlayingContext(o.playData)) {
					isAnyPlaying = true;
				}
			}
		});
		if (isAnyPlaying) {
			Array.prototype.forEach.call(NoteList.childNodes, function (e) {
				var item = getNoteItemData(e);
				if (item) {
					var o = item.data;
					if (o && o.playData) {
						output.stopContext(o.playData);
					}
				}
			});
		} else {
			Array.prototype.forEach.call(NoteList.childNodes, function (e) {
				var item = getNoteItemData(e);
				if (item) {
					playNoteItem(item);
				}
			});
		}
	};
};

/**
 * @param {NoteItemObject} item
 * @param {string} propName
 */
var getChangeNoteItemDataHandler = function (item, propName) {
	return function (e) {
		item.data[propName] = e.target.value;
		updateLastValues();
	};
};

/**
 * @param {NoteItemObject} item
 */
var initializeNoteItemElement = function (item) {
	_addEventListenerForClassFirst(item.element, 'notePlaySingle', 'click', getNoteItemPlaySingleHandler(item), false);
	_addEventListenerForClassFirst(item.element, 'noteRemove', 'click', getNoteItemRemoveHandler(item), false);
	_addEventListenerForClassFirst(item.element, 'noteItemValue', 'change', getChangeNoteItemDataHandler(item, 'hz'), false);
	_addEventListenerForClassFirst(item.element, 'noteFunction', 'change', getChangeNoteItemDataHandler(item, 'func'), false);
};

/**
 * @return {NoteDataObject}
 * @param {number} hz
 * @param {function(number):number} func
 */
var createNoteDataObject = function (hz, func) {
	var o = { hz: hz, func: func, playData: null };
	o.toString = function () { return this.hz + ':' + this.func; };
	return o;
};

var addNoteWithElement = function (elem, noGenerateDataObject) {
	var o = null;
	if (!noGenerateDataObject) {
		o = createNoteDataObject(getValueFromClassName(elem, 'noteItemValue'), getValueFromClassName(elem, 'noteFunction'));
		NoteItemValues.push(o);
		updateLastValues();
	}
	var x = {
		element: elem,
		data: o
	};
	initializeNoteItemElement(x);
	NoteItems.push(x);
	return x;
};

var addNote = function (noGenerateDataObject) {
	var item = document.createElement('li');
	item.className = 'noteItem';
	item.innerHTML = NoteItemHtml;
	NoteList.appendChild(item);
	return addNoteWithElement(item, noGenerateDataObject);
};

var getNoteItemData = function (elem) {
	for (var i = NoteItems.length - 1; i >= 0; --i) {
		var o = NoteItems[i];
		if (o.element === elem)
			return o;
	}
	return null;
};

var removeNote = function (item) {
	var o = item.data;
	removeNoteObject(o);
	NoteList.removeChild(item.element);
	if (o.playData && output.isPlayingContext(o.playData)) {
		output.stopContext(o.playData);
	}
	for (var i = NoteItems.length - 1; i >= 0; --i) {
		if (NoteItems[i] === item) {
			NoteItems.splice(i, 1);
			return;
		}
	}
};

var onClickAddNote = function () {
	addNote();
};

var onClickRemoveLastNote = function () {
	var elem = NoteList.lastChild;
	while (item) {
		var itemData = getNoteItemData(elem);
		if (itemData) {
			removeNote(itemData);
			return;
		}
		elem = elem.previousSibling;
	}
};

var updateCalculatorValues = function () {
	var elems = document.getElementsByClassName("hzCalculatorForm");
	if (!elems || !elems.length)
		return;
	var num = Number(getValueFromClassName(elems[0], "calc_value"));

	var p = getSelectElementSelectedValueFromClassName(elems[0], "calc_typeJust");
	setInnerTextForElementId("calc_justValue", JustIntonationFunctions[Number(p)](num));

	p = getSelectElementSelectedValueFromClassName(elems[0], "calc_typeEqual");
	setInnerTextForElementId("calc_equalValue", num * Math.pow(2, Number(p) / 12));

	setInnerTextForElementId("calc_twiceNote", num * 2);
	setInnerTextForElementId("calc_halfTripleNote", num * 3 / 2);
	setInnerTextForElementId("calc_tripleNote", num * 3);
	setInnerTextForElementId("calc_upperOne", num * Math.pow(2, 1/12));
	setInnerTextForElementId("calc_upperTwo", num * Math.pow(2, 1/6));
	setInnerTextForElementId("calc_upper3", num * Math.pow(2, 1/4));
	setInnerTextForElementId("calc_upper4", num * Math.pow(2, 1/3));
	setInnerTextForElementId("calc_lowerOne", num * Math.pow(2, -1/12));
	setInnerTextForElementId("calc_lowerTwo", num * Math.pow(2, -1/6));
};

var onInputCalculatorValue = function () {
	updateCalculatorValues();
};

var initialize = function () {
	_addEventListenerForId('buttonPlayAll', 'click', getPlayAllHandler(), false);
	_addEventListenerForId('buttonAdd', 'click', onClickAddNote, false);
	_addEventListenerForId('buttonRemove', 'click', onClickRemoveLastNote, false);

	var elems = document.getElementsByClassName("hzCalculatorForm");
	if (!elems || !elems.length)
		return;
	_addEventListenerForClassFirst(elems[0], 'calc_value', 'input', onInputCalculatorValue, false);
	_addEventListenerForClassFirst(elems[0], 'calc_typeJust', 'change', onInputCalculatorValue, false);
	_addEventListenerForClassFirst(elems[0], 'calc_typeEqual', 'change', onInputCalculatorValue, false);
	updateCalculatorValues();
};

var _preInitialize = function () {
	{
		ErrorMessageElement = document.getElementById('errorMessage');
		if (!ErrorMessageElement)
			return;
		NoteList = document.getElementById('noteList');
		if (!NoteList)
			return;
		NoteItemLastValuesElement = document.getElementById('noteItemLastValues');
		if (!NoteItemLastValuesElement)
			return;
		NoteItemCountElement = document.getElementById('noteItemCurrentCount');
		if (!NoteItemCountElement)
			return;
		var itemElem = null;
		Array.prototype.forEach.call(NoteList.childNodes, function (e) {
			if (isNoteItemElement(e))
				itemElem = e;
		});
		if (!itemElem)
			return;
		NoteItemHtml = itemElem.innerHTML;
		var s = NoteItemLastValuesElement.value;

		var item = addNoteWithElement(itemElem, false);
		//initializeNoteItemElement(item);

		if (s) {
			var itemValues = s.split("\n");
			var c = itemValues.length;
			if (c < 1) {
				removeNote(item);
			} else {
				itemValues.forEach(function (x) {
					var itemValue = x.split(":", 2);
					item.data.hz = Number(itemValue[0]);
					item.data.func = itemValue[1];
					setValueFromClassName(item.element, 'noteItemValue', item.data.hz);
					setValueFromClassName(item.element, 'noteFunction', item.data.func);
					if (c-- > 1)
						item = addNote();
				});
			}
			updateLastValues();
		} else {
			var c = Number(NoteItemCountElement.value);
			if (c < 1) {
				removeNote(item);
			} else {
				while (c-- > 1) {
					addNote();
				}
			}
		}
	}

	if (!PF.Wave.isAvailable()) {
		document.body.className += ' notSupported';
	}

	window.addEventListener('DOMContentLoaded', initialize, false);
};
preInitialize = _preInitialize;

})();
