<?php
/**
 * Theme social links.
 **/
$api_key = trim(variable_get('socialloginandsocialshare_apikey'));
if (!empty($api_key)) {
$my_settings = array(
  'interfacesize' => $interfaceiconsize,
  'lrinterfacebackground' => $interfacebackgroundcolor,
  'noofcolumns' => $interfacerow,
  'apikey' => $api_key,
  'location' => $loc,
  'callback' => url('', array('absolute' => TRUE)),
);
  drupal_add_js(array('lrsociallogin' => $my_settings), 'setting');
  ?>
  <script type="text/javascript"
          src="<?php print $GLOBALS['base_url'] ?>/<?php echo drupal_get_path('module', 'socialloginandsocialshare') ?>/js/sociallogin_interface.js">
  </script>
<?php
}
?>
<div class="interfacecontainerdiv"></div>
