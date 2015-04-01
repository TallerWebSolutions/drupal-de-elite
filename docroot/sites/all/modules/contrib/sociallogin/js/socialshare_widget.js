if (typeof LoginRadius != 'undefined') {
  if (Drupal.settings.lrsocialshare != undefined) {
    if (Drupal.settings.lrsocialshare.sharing != undefined && Drupal.settings.lrsocialshare.sharing) {
      LoginRadius.util.ready(function () {
        var lr_interface = Drupal.settings.lrsocialshare.lr_interface;
        $i = $SS.Interface[lr_interface];
        var string = Drupal.settings.lrsocialshare.providers;
        var providers = string.split(',');
        $SS.Providers.Top = providers;
        $u = LoginRadius.user_settings;
        if (Drupal.settings.lrsocialshare.apikey) {
          $u.apikey = Drupal.settings.lrsocialshare.apikey;
        }
        $u.sharecounttype = 'url';
        $i.size = Drupal.settings.lrsocialshare.size;
        $i.top = '0px';
        $i.left = '0px';
        $i.show(Drupal.settings.lrsocialshare.divwidget);
      });
    }
    if (Drupal.settings.lrsocialshare.counter != undefined && Drupal.settings.lrsocialshare.counter) {
      LoginRadius.util.ready(function () {
        var string = Drupal.settings.lrsocialshare.providers;
        var providers = string.split(',');
        var lr_interface = Drupal.settings.lrsocialshare.lr_interface;
        $SC.Providers.Selected = providers;
        $S = $SC.Interface[lr_interface];
        $S.isHorizontal = true;
        $S.countertype = Drupal.settings.lrsocialshare.countertype;
        $S.show(Drupal.settings.lrsocialshare.divwidget);
      });
    }
    if (Drupal.settings.lrsocialshare.verticalsharing != undefined && Drupal.settings.lrsocialshare.verticalsharing) {
      LoginRadius.util.ready(function () {
        var lr_interface = Drupal.settings.lrsocialshare.lr_vertical_interface;
        $i = $SS.Interface[lr_interface];
        var string = Drupal.settings.lrsocialshare.vertical_providers;
        var providers = string.split(',');
        $SS.Providers.Top = providers;
        $u = LoginRadius.user_settings;
        if (Drupal.settings.lrsocialshare.vertical_apikey) {
          $u.apikey = Drupal.settings.lrsocialshare.vertical_apikey;
        }
        $u.sharecounttype = 'url';
        $i.size = Drupal.settings.lrsocialshare.vertical_size;
        $i[Drupal.settings.lrsocialshare.vertical_position1] = '0px';
        $i[Drupal.settings.lrsocialshare.vertical_position2] = '0px';
        $i.show(Drupal.settings.lrsocialshare.vertical_divwidget);
      });
    }
    if (Drupal.settings.lrsocialshare.verticalcounter != undefined && Drupal.settings.lrsocialshare.verticalcounter) {
      LoginRadius.util.ready(function () {
        var string = Drupal.settings.lrsocialshare.vertical_providers;
        var providers = string.split(',');
        $SC.Providers.Selected = providers;
        $S = $SC.Interface.simple;
        $S.isHorizontal = false;
        $S.countertype = Drupal.settings.lrsocialshare.vertical_countertype;
        $S[Drupal.settings.lrsocialshare.vertical_position1] = '0px';
        $S[Drupal.settings.lrsocialshare.vertical_position2] = '0px';
        $S.show(Drupal.settings.lrsocialshare.vertical_divwidget);
      });
    }
  }
}