<?php

/**
 * @file
 * Sdk page callback file for the socialloginandsocialshare module.
 * This class should be used only for Drupal site.
 */
class LoginRadius {

  public $isauthenticated, $userprofile, $isauth, $userauth, $jsonresponse, $iserror;

  /**
   * Function to handle LoginRadius request for profile data.
   */
  public function loginradius_get_data($apisecrete, $api_handler) {
    $isauthenticated = FALSE;
    global $base_url;
    if (isset($_REQUEST['token'])) {
      $validateurl =  "https://hub.loginradius.com/UserProfile/" . $apisecrete . "/" . $_REQUEST['token'];
      $userprofile = $this->loginradius_call_api($validateurl, $api_handler);
      if (isset($userprofile->ID) && $userprofile->ID != '') {
        $this->isauthenticated = TRUE;
        return $userprofile;
      }
      else {
        $this->iserror = TRUE;
        return;
      }
    }
  }

  /**
   * Function to authenticate LoginRadius API key and secret.
   */
  public function loginradius_get_auth($apikey, $apisecret, $api_handler) {
    $isauth = FALSE;
    if (isset($apikey)) {
      $apikey = trim($apikey);
      $apisecret = trim($apisecret);
      $validateurl ="https://hub.loginradius.com/ping/$apikey/$apisecret";
      $userauth = $this->loginradius_call_api($validateurl, $api_handler);
      if (isset($userauth->ok)) {
        return "connection working";
      }
      elseif ($userauth == "service connection timeout") {
        return "service connection timeout";
      }
      elseif ($userauth == "timeout") {
        return "timeout";
      }
      else {
        return "connection error";
      }
    }
  }
  
  /**
   * Function to get response from loginradius.
   */
  public function loginradius_call_api($validateurl, $api_handler) {
    global $base_url;
    if ($api_handler == 0) {
      $headers = array(
        'Referer' => $base_url,
        'User-Agent' => 'socialloginandsocialshare_Module',
      );
      $options = array(
        'headers' => $headers,
        'max_redirects' => 5,
      );
      $result = drupal_http_request($validateurl, $options);
      $userprofile = json_decode($result->data);
      if (is_object($result) && property_exists($result, 'code')) {
        if ($result->code == 400 || $result->code == 401 || $result->code == 403 || $result->code == 404 || $result->code == 500|| $result->code == 503) {
          return "service connection timeout";
        }
      }
    }
    else {
      if (in_array ('curl', get_loaded_extensions ()) AND function_exists('curl_exec')) {
        $curl_handle = curl_init();
        curl_setopt($curl_handle, CURLOPT_URL, $validateurl);
        curl_setopt($curl_handle, CURLOPT_CONNECTTIMEOUT, 0);
        curl_setopt($curl_handle, CURLOPT_TIMEOUT, 0);
        curl_setopt($curl_handle, CURLOPT_SSL_VERIFYPEER, FALSE);
        if (ini_get('open_basedir') == '' && (ini_get('safe_mode') == 'Off' or !ini_get('safe_mode'))) {
          curl_setopt($curl_handle, CURLOPT_FOLLOWLOCATION, 1);
          curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, TRUE);
        }
        else {
          curl_setopt($curl_handle, CURLOPT_HEADER, 1);
          $url = curl_getinfo($curl_handle, CURLINFO_EFFECTIVE_URL);
          curl_close($curl_handle);
          $curl_handle = curl_init();
          $url = str_replace('?', '/?', $url);
          curl_setopt($curl_handle, CURLOPT_URL, $url);
          curl_setopt($curl_handle, CURLOPT_SSL_VERIFYPEER, FALSE);
          curl_setopt($curl_handle, CURLOPT_RETURNTRANSFER, TRUE);
        }
        $jsonresponse = curl_exec($curl_handle);
        $http_code = curl_getinfo($curl_handle, CURLINFO_HTTP_CODE);
        if (in_array($http_code, array(400, 401, 403, 404, 500, 503)) && $http_code != 200) {
          return "service connection timeout";
        }
        elseif (curl_errno($curl_handle) == 28) {
          return "timeout";
        }
        curl_close($curl_handle);
        $userprofile = json_decode($jsonresponse);
      }
    }
    return $userprofile;
  }
}
