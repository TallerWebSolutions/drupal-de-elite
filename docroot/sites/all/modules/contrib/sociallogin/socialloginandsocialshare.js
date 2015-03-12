var selectedSharingTheme = document.getElementsByName('socialloginandsocialshare_selected_share_interface');
var selectedCounterTheme = document.getElementsByName('socialloginandsocialshare_selected_counter_interface');
var selectedProviderList= document.getElementsByName('socialloginandsocialshare_rearrange_providers_list[]');
var selectedcounterProviderList= document.getElementsByName('socialcounter_rearrange_providers_list[]');
var selectedcounterverticalProviderList= document.getElementsByName('socialcounter_vertical_rearrange_providers_list[]');
var selectedverticalProviderList= document.getElementsByName('socialshare_vertical_rearrange_providers_list[]');
document.write("<script type='text/javascript'>var islrsharing = true; var islrsocialcounter = true;</script>");
document.write("<script src='//share.loginradius.com/Content/js/LoginRadius.js' type='text/javascript'></script>");
window.onload = function(){
	 jQuery("#edit-socialloginandsocialshare-share-horizontal-images-0,#edit-socialloginandsocialshare-share-horizontal-images-1").click(function(){
		sharing_horizonatl_show(); 
	});  
	  jQuery("#edit-socialloginandsocialshare-share-horizontal-images-2,#edit-socialloginandsocialshare-share-horizontal-images-3").click(function(){
		sharing_horizonatl_show();
		sharing_simplehorizonatl_show();
	}); 
	 jQuery("#edit-socialloginandsocialshare-share-horizontal-images-8,#edit-socialloginandsocialshare-share-horizontal-images-9").click(function(){
		counter_horizntal_show();
    }); 
	    jQuery("#edit-socialloginandsocialshare-share-vertical-images-4,#edit-socialloginandsocialshare-share-vertical-images-5").click(function(){
	sharing_vertical_show();
    });  
	 jQuery("#edit-socialloginandsocialshare-share-vertical-images-6,#edit-socialloginandsocialshare-share-vertical-images-7").click(function(){
		counter_vertical_show();
    });  
	sharingproviderlist();
	counterproviderlist();
	verticalsharingproviderlist();
	verticalcounterproviderlist();	
  jQuery("#socialloginandsocialshare_rearrange_providers").sortable({
    revert: true
  });
   jQuery("#socialshare_vertical_rearrange_providers").sortable({
    revert: true
  });
     loginRadiusToggleShareTheme(selectedSharingTheme[0].value);
     jQuery(".socialloginandsocialshare_rearrange_providers").find("li").unwrap();
	 jQuery(".socialshare_vertical_rearrange_providers").find("li").unwrap();
	 jQuery("#socialloginandsocialshare_veritical").click(function(){
       loginRadiusToggleShareTheme("vertical");
	 });
	 jQuery("#socialloginandsocialshare_horizontal").click(function(){															
       loginRadiusToggleShareTheme("horizontal");
	 });
  }
 // Sharing Theme selected.
function loginRadiusToggleShareTheme(theme){
  selectedSharingTheme[0].value=theme;
  if(theme == "vertical"){
    verticalDisplay = 'block';
	horizontalDisplay = 'none';
	marginleft ='78px';
    jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-position").removeClass("element-invisible");
    }else{
    verticalDisplay = 'none';
    horizontalDisplay = 'block';
	marginleft ='20px';
    jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-position").addClass("element-invisible");
}
document.getElementById('socialloginandsocialshare_share_horizontal_images').style.display = horizontalDisplay;
document.getElementById('socialloginandsocialshare_share_vertical_images').style.display = verticalDisplay;
document.getElementById('lrsharing_divwhite').style.marginLeft  = marginleft;
document.getElementById('lrsharing_divgrey').style.marginLeft  = marginleft;
}

/*
* Show sharing Rearrange Providers.
*/
function loginRadiusRearrangeProviderList(elem){
var ul = document.getElementById('socialloginandsocialshare_rearrange_providers');
var input = document.getElementById('socialloginandsocialshare_chnage_name');
if(elem.checked){
  var listItem = document.createElement('li');
  listItem.setAttribute('id', 'edit-lrshare-iconsprite32'+elem.value);
  listItem.setAttribute('title', elem.value);
  listItem.setAttribute('class', 'lrshare_iconsprite32 lrshare_'+elem.value);
  var provider = document.createElement('input');
  provider.setAttribute('type', 'hidden');
  provider.setAttribute('id', 'input-lrshare-'+elem.value);
  provider.setAttribute('name', 'socialloginandsocialshare_rearrange_providers_list[]');
  provider.setAttribute('value',elem.value);
  listItem.appendChild(provider);
  ul.appendChild(listItem);
  }else{
	   if(document.getElementById('edit-lrshare-iconsprite32'+elem.value)){
   ul.removeChild(document.getElementById('edit-lrshare-iconsprite32'+elem.value));
	   }
  }
}

/*
* Show Counter Providers selected.
*/
function loginRadiuscounterProviderList(elem){
var ul = document.getElementById('socialcounter_show_providers_list');
var raw= elem.value;
var value= elem.value.split(' ').join('');
value = value.replace("++", "plusplus");
value = value.replace("+", "plus");
if(elem.checked){
 var provider = document.createElement('input');
  provider.setAttribute('type', 'hidden');
  provider.setAttribute('id', 'input-lrcounter-'+value);
  provider.setAttribute('name', 'socialcounter_rearrange_providers_list[]');
  provider.setAttribute('value',raw);
  ul.appendChild(provider);
}
else {
	jQuery('#input-lrcounter-'+value).remove();
	jQuery('#edit-'+value).remove();
 }
}
// Provider list selcted in vertical counter.
function loginRadiuscounterverticalProviderList(elem){
var ul = document.getElementById('socialcounter_vertical_show_providers_list');
var raw= elem.value;
var value= elem.value.split(' ').join('');
value = value.replace("++", "plusplus");
value = value.replace("+", "plus");
if(elem.checked){
 var provider = document.createElement('input');
  provider.setAttribute('type', 'hidden');
  provider.setAttribute('id', 'input-lrcounter-vertical-'+value);
  provider.setAttribute('name', 'socialcounter_vertical_rearrange_providers_list[]');
  provider.setAttribute('value',raw);
  ul.appendChild(provider);
}
else {
	jQuery('#input-lrcounter-vertical-'+value).remove();
	jQuery('#edit-lrshare-vertical-'+value).remove();
 }
}
// check limit for horizontal Social sharing.
function loginRadiusSharingLimit(elem){
	var checkCount = selectedProviderList.length;
     if(elem.checked){
			// count checked providers
			checkCount++;
			if(checkCount >= 10){
				elem.checked = false;
					jQuery("#loginRadiusSharingLimit").show('slow');
				setTimeout(function() {
					jQuery("#loginRadiusSharingLimit").hide('slow');
				}, 2000);
				return;
			}
	}
}
// check limit for vertical Social sharing.
function loginRadiusverticalSharingLimit(elem){
	var checkCount = selectedverticalProviderList.length;
     if(elem.checked){
			// count checked providers
			checkCount++;
			if(checkCount >= 10){
				elem.checked = false;
				jQuery("#loginRadiusSharingLimit_vertical").show('slow');
				setTimeout(function() {
					jQuery("#loginRadiusSharingLimit_vertical").hide('slow');
				}, 2000);
				return;
			}
	}
}
// show Provider List for vertical Social Sharing.
function verticalsharingproviderlist() {
	var sharing =  $SS.Providers.More;
	var div = document.getElementById('socialshare_vetical_show_providers_list');
	for( var i= 0 ; i< sharing.length;i++){
		 var listItem = document.createElement('div');
  		 listItem.setAttribute('class', 'form-item form-type-checkbox form-item-socialshare-vertical-show-providers-list-'+sharing[i].toLowerCase());
		 var provider = document.createElement('input');
		 provider.setAttribute('type', 'checkbox');
		 provider.setAttribute('id', 'edit-socialshare-vertical-show-providers-list-'+sharing[i].toLowerCase());
		 provider.setAttribute('onchange', 'loginRadiusverticalSharingLimit(this); loginRadiusverticalRearrangeProviderList(this);');
		 provider.setAttribute('name', 'socialshare_vertical_show_providers_list['+sharing[i].toLowerCase()+']');
		  provider.setAttribute('value', sharing[i].toLowerCase());
		  provider.setAttribute('class', 'form-checkbox');  
		 var label = document.createElement('label');
		  label.setAttribute('for', 'edit-socialshare-vertical-show-providers-list-'+sharing[i].toLowerCase());
		  label.setAttribute('class','option');
		   var labeltext = document.createTextNode(sharing[i]);

          label.appendChild(labeltext);
		  listItem.appendChild(provider);
		   listItem.appendChild(label);
		  div.appendChild(listItem);
	}
	if(selectedverticalProviderList.length >0) {
		for(var i = 0; i < selectedverticalProviderList.length; i++){
			if(!selectedverticalProviderList[i].checked){
				jQuery('#edit-socialshare-vertical-show-providers-list-'+selectedverticalProviderList[i].value).attr('checked','checked');
			}
		}
	}
}
//// show Provider List for vertical Social counter.
function verticalcounterproviderlist(){
	var counter = $SC.Providers.All;
	var div = document.getElementById('socialcounter_vertical_show_providers_list');
		for( var i= 0 ; i< counter.length;i++){
		var value= counter[i].split(' ').join('');
		value = value.replace("++", "plusplus");
		value = value.replace("+", "plus");
		 var listItem = document.createElement('div');
  		 listItem.setAttribute('class', 'form-item form-type-checkbox form-item-socialshare_counter_vertical_show_providers_list-'+counter[i]);
		 var provider = document.createElement('input');
		 provider.setAttribute('type', 'checkbox');
		 provider.setAttribute('id', 'edit-socialshare-counter-vertical-show-providers-list-'+value);
		 provider.setAttribute('onchange', 'loginRadiuscounterverticalProviderList(this);');
		 provider.setAttribute('name', 'socialcounter_new_vertical_providers_list[]');
		  provider.setAttribute('value', counter[i]);
		  provider.setAttribute('class', 'form-checkbox');
		  var divtag = document.createElement('div');
		  divtag.setAttribute('id', 'edit-socialshare-counter-vertical-show-providers-list');
		  divtag.setAttribute('class', 'form-checkboxes');
		 var label = document.createElement('label');
		  label.setAttribute('for', 'edit-socialshare-counter-show-vertical-providers-list-'+counter[i]);
		  label.setAttribute('class','option');
		   var labeltext = document.createTextNode(counter[i]);
          label.appendChild(labeltext);
		  listItem.appendChild(provider);
		  listItem.appendChild(label);
		  div.appendChild(listItem);
		  
	}
	if(selectedcounterverticalProviderList.length >0) {
		for(var i = 0; i < selectedcounterverticalProviderList.length; i++){
			if(!selectedcounterverticalProviderList[i].checked){
				var value= selectedcounterverticalProviderList[i].value.split(' ').join('');
				value = value.replace("++", "plusplus");
                value = value.replace("+", "plus");
				jQuery('#edit-socialshare-counter-vertical-show-providers-list-'+value).attr('checked','checked');
			}
		}
	}
}
// show Provider List for horizontal Social Sharing.
function sharingproviderlist(){
	var sharing =  $SS.Providers.More;
	var div = document.getElementById('socialshare_providers_list');
	for( var i= 0 ; i< sharing.length;i++){
		 var listItem = document.createElement('div');
  		 listItem.setAttribute('class', 'form-item form-type-checkbox form-item-socialshare-show-providers-list-'+sharing[i].toLowerCase());
		 var provider = document.createElement('input');
		 provider.setAttribute('type', 'checkbox');
		 provider.setAttribute('id', 'edit-socialshare-show-providers-list-'+sharing[i].toLowerCase());
		 provider.setAttribute('onchange', 'loginRadiusSharingLimit(this); loginRadiusRearrangeProviderList(this);');
		 provider.setAttribute('name', 'socialshare_show_providers_list['+sharing[i].toLowerCase()+']');
		  provider.setAttribute('value', sharing[i].toLowerCase());
		  provider.setAttribute('class', 'form-checkbox');
		 var label = document.createElement('label');
		  label.setAttribute('for', 'edit-socialshare-show-providers-list-'+sharing[i].toLowerCase());
		  label.setAttribute('class','option');
		   var labeltext = document.createTextNode(sharing[i]);
          label.appendChild(labeltext);
		  listItem.appendChild(provider);
		   listItem.appendChild(label);
		  div.appendChild(listItem);
	}
	if(selectedProviderList.length >0) {
		for(var i = 0; i < selectedProviderList.length; i++){
			if(!selectedProviderList[i].checked){
				jQuery('#edit-socialshare-show-providers-list-'+selectedProviderList[i].value).attr('checked','checked');
			}
		}
	}
}
// show Provider List for horizontal Social counter.
function counterproviderlist() {
	var counter = $SC.Providers.All;
	var div = document.getElementById('socialcounter_show_providers_list');
		for( var i= 0 ; i< counter.length;i++){
		var value= counter[i].split(' ').join('');
		value = value.replace("++", "plusplus");
		value = value.replace("+", "plus");
		 var listItem = document.createElement('div');
  		 listItem.setAttribute('class', 'form-item form-type-checkbox form-item-socialshare_counter_show_providers_list-'+counter[i]);
		 var provider = document.createElement('input');
		 provider.setAttribute('type', 'checkbox');
		 provider.setAttribute('id', 'edit-socialshare-counter-show-providers-list-'+value);
		 provider.setAttribute('onchange', 'loginRadiuscounterProviderList(this);');
		 provider.setAttribute('name', 'socialcounter_providers_list[]');
		  provider.setAttribute('value', counter[i]);
		  provider.setAttribute('class', 'form-checkbox');
		  var divtag = document.createElement('div');
		  divtag.setAttribute('id', 'edit-socialshare-counter-show-providers-list');
		  divtag.setAttribute('class', 'form-checkboxes');
		 var label = document.createElement('label');
		  label.setAttribute('for', 'edit-socialshare-counter-show-providers-list-'+counter[i]);
		  label.setAttribute('class','option');
		   var labeltext = document.createTextNode(counter[i]);
          label.appendChild(labeltext);
		  listItem.appendChild(provider);
		  listItem.appendChild(label);
		  div.appendChild(listItem);	  
	}
	if(selectedcounterProviderList.length >0) {
		for(var i = 0; i < selectedcounterProviderList.length; i++){
			if(!selectedcounterProviderList[i].checked){
				var value= selectedcounterProviderList[i].value.split(' ').join('');
				value = value.replace("++", "plusplus");
                value = value.replace("+", "plus");
				jQuery('#edit-socialshare-counter-show-providers-list-'+value).attr('checked','checked');
			}
		}
	}
}
// show Sharing Horizontal
function sharing_horizonatl_show(){
	jQuery("#socialcounter_show_providers_list").addClass("element-invisible");
	jQuery("#socialshare_providers_list").removeClass("element-invisible");
	jQuery("#rearrange_sharing_text").removeClass("element-invisible");
	jQuery("#socialloginandsocialshare_rearrange_providers").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-horizontal-location").removeClass("addtopmargin");
}
function sharing_simplehorizonatl_show(){
	jQuery("#socialshare_providers_list").addClass("element-invisible");
	jQuery("#rearrange_sharing_text").addClass("element-invisible");
	jQuery("#socialloginandsocialshare_rearrange_providers").addClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-horizontal-location").addClass("addtopmargin");
}
// Show sharing vertical.
function sharing_vertical_show(){
	jQuery("#socialcounter_vertical_show_providers_list").addClass("element-invisible");
	jQuery("#socialshare_vetical_show_providers_list").removeClass("element-invisible");
	jQuery("#rearrange_sharing_text_vertical").removeClass("element-invisible");
	jQuery("#socialshare_vertical_rearrange_providers").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-location").removeClass("addtopmargin");
}
// show Counter Vertical.
function counter_vertical_show(){
	jQuery("#socialcounter_vertical_show_providers_list").removeClass("element-invisible");
	jQuery("#socialshare_vetical_show_providers_list").addClass("element-invisible");
	jQuery("#rearrange_sharing_text_vertical").addClass("element-invisible");
	jQuery("#socialshare_vertical_rearrange_providers").addClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-location").addClass("addtopmargin");
}

// show Counter Horizontal .
function counter_horizntal_show(){
	jQuery("#socialshare_providers_list").addClass("element-invisible");
	jQuery("#rearrange_sharing_text").addClass("element-invisible");
	jQuery("#socialloginandsocialshare_rearrange_providers").addClass("element-invisible");
	jQuery("#socialcounter_show_providers_list").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-horizontal-location").addClass("addtopmargin");
}

// Show only vertical widget options.
function hidden_horizontal_widget(){
	jQuery("#socialloginandsocialshare_show_horizotal_widget").addClass("element-invisible");
	jQuery("#socialloginandsocialshare_show_veritcal_widget").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-show-pages").addClass("element-invisible");
	jQuery(".form-item.form-type-textarea.form-item-socialshare-show-exceptpages").addClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-show-pages").removeClass("element-invisible");
	jQuery(".form-item.form-type-textarea.form-item-socialshare-vertical-show-exceptpages").removeClass("element-invisible");
	jQuery(".form-item.form-type-textfield.form-item-socialshare-label-string").addClass("element-invisible");
	jQuery("#horizontal_sharing_show").addClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialloginandsocialshare-enable-horizontal-share").addClass("element-invisible");
	jQuery(".form-item.form-type-select.form-item-socialshare-top-weight").addClass("element-invisible");
	jQuery(".form-item.form-type-select.form-item-socialshare-bottom-weight").addClass("element-invisible");
	
	jQuery(".form-item.form-type-radios.form-item-socialloginandsocialshare-enable-vertical-share").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-location").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-horizontal-location").addClass("element-invisible");
	var isChecked = jQuery("#edit-socialshare-vertical-location-block")[0].checked;
	if(isChecked) {
		display_block_vertical("block");	
	}
	else {
		display_block_vertical("content");	
	}
}
// Show only Horizontal widget options.
function display_horizontal_widget(){
	jQuery("#socialloginandsocialshare_show_horizotal_widget").removeClass("element-invisible");
	jQuery("#socialloginandsocialshare_show_veritcal_widget").addClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-show-pages").removeClass("element-invisible");
	jQuery(".form-item.form-type-textarea.form-item-socialshare-show-exceptpages").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-show-pages").addClass("element-invisible");
	jQuery(".form-item.form-type-textarea.form-item-socialshare-vertical-show-exceptpages").addClass("element-invisible");
	jQuery(".form-item.form-type-textfield.form-item-socialshare-label-string").removeClass("element-invisible");
	jQuery("#horizontal_sharing_show").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialloginandsocialshare-enable-horizontal-share").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialloginandsocialshare-enable-vertical-share").addClass("element-invisible");
	jQuery(".form-item.form-type-select.form-item-socialshare-top-weight").removeClass("element-invisible");
	jQuery(".form-item.form-type-select.form-item-socialshare-bottom-weight").removeClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-location").addClass("element-invisible");
	jQuery(".form-item.form-type-radios.form-item-socialshare-horizontal-location").removeClass("element-invisible");
	var isChecked = jQuery("#edit-socialshare-horizontal-location-block")[0].checked;
	if(isChecked) {
		display_block_horizontal("block");	
	}
	else {
		display_block_horizontal("content");	
	}
}

// vertical Sharing Rearrange counter
function loginRadiusverticalRearrangeProviderList(elem){
var ul = document.getElementById('socialshare_vertical_rearrange_providers');
var input = document.getElementById('socialshare_chnage_name');
if(elem.checked){
  var listItem = document.createElement('li');
  listItem.setAttribute('id', 'edit-lrshare-iconsprite32_vertical'+elem.value);
  listItem.setAttribute('title', elem.value);
  listItem.setAttribute('class', 'lrshare_iconsprite32 lrshare_'+elem.value);
  var provider = document.createElement('input');
  provider.setAttribute('type', 'hidden');
  provider.setAttribute('id', 'input-lrshare-vertical-'+elem.value);
  provider.setAttribute('name', 'socialshare_vertical_rearrange_providers_list[]');
  provider.setAttribute('value',elem.value);
  listItem.appendChild(provider);
  ul.appendChild(listItem);
  }else{
	  if(document.getElementById('edit-lrshare-iconsprite32_vertical'+elem.value)){
   ul.removeChild(document.getElementById('edit-lrshare-iconsprite32_vertical'+elem.value));
	  }
  }
}

// Check to horizontal display Block or content.
function display_block_horizontal(value){
	if (value == "block") {
		jQuery("#horizontal_sharing_show").addClass("element-invisible");
		jQuery(".form-item.form-type-select.form-item-socialshare-top-weight").addClass("element-invisible");
		jQuery(".form-item.form-type-select.form-item-socialshare-bottom-weight").addClass("element-invisible");
		jQuery(".form-item.form-type-radios.form-item-socialshare-show-pages").addClass("element-invisible");
		jQuery(".form-item.form-type-textarea.form-item-socialshare-show-exceptpages").addClass("element-invisible");
	}
	else {
		jQuery("#horizontal_sharing_show").removeClass("element-invisible");
		jQuery(".form-item.form-type-select.form-item-socialshare-top-weight").removeClass("element-invisible");
		jQuery(".form-item.form-type-select.form-item-socialshare-bottom-weight").removeClass("element-invisible");
		jQuery(".form-item.form-type-radios.form-item-socialshare-show-pages").removeClass("element-invisible");
		jQuery(".form-item.form-type-textarea.form-item-socialshare-show-exceptpages").removeClass("element-invisible");
	}
}

// Check to vertical display Block or content.
function display_block_vertical(value){
	if (value == "block") {
		jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-show-pages").addClass("element-invisible");
		jQuery(".form-item.form-type-textarea.form-item-socialshare-vertical-show-exceptpages").addClass("element-invisible");
	}
	else {
		jQuery(".form-item.form-type-radios.form-item-socialshare-vertical-show-pages").removeClass("element-invisible");
		jQuery(".form-item.form-type-textarea.form-item-socialshare-vertical-show-exceptpages").removeClass("element-invisible");
	}
}
