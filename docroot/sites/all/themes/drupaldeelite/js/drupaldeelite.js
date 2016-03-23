(function ($, Drupal) {

  // Invert colors in internal post pages.
  Drupal.behaviors.invertColors = {
    attach: function(context, settings) {
      var $invertButton = $('.invert-colors', context),
          $page = $('.page');

      $invertButton.on('click', function(e) {
        e.preventDefault();
        $page.toggleClass('inverted');
      });
    }
  };

})(jQuery, Drupal);
