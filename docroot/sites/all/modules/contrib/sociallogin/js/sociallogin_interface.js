var options={}; options.login=true;
LoginRadius_SocialLogin.util.ready(function ()
{ $ui = LoginRadius_SocialLogin.lr_login_settings;
    $ui.interfacesize = Drupal.settings.lrsociallogin.interfacesize;
    $ui.lrinterfacebackground=Drupal.settings.lrsociallogin.lrinterfacebackground;
    $ui.noofcolumns= Drupal.settings.lrsociallogin.noofcolumns;
    $ui.apikey = Drupal.settings.lrsociallogin.apikey;
    $ui.is_access_token=true;
    $ui.callback=Drupal.settings.lrsociallogin.callback;
    $ui.lrinterfacecontainer ="interfacecontainerdiv"; LoginRadius_SocialLogin.init(options); });
LoginRadiusSDK.setLoginCallback(function () {
    var token = LoginRadiusSDK.getToken();
    var form = document.createElement('form');
    form.action = Drupal.settings.lrsociallogin.location;
    form.method = 'POST';

    var hiddenToken = document.createElement('input');
    hiddenToken.type = 'hidden';
    hiddenToken.value = token;
    hiddenToken.name = 'token';
    form.appendChild(hiddenToken);

    document.body.appendChild(form);
    form.submit();
});