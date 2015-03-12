(function ($) {
  Drupal.behaviors.web = {
    attach: function(context, settings) {
      
      // Tradução do chat
      $zopim(function() {
              
        $zopim.livechat.setLanguage('pt');
      
        $zopim.livechat.bubble.setTitle('Dúvidas?');
        $zopim.livechat.bubble.setText('Clique aqui para falar conosco');

        $zopim.livechat.setGreetings({
          'online':  ['Clique aqui chat',  'Deixar uma pergunta ou comentário que iremos responder =)'],
          'offline': ['Deixe o sua menssagem', 'Deixe seu contato e sua pergunta que em breve responderemos =)'],
          'away':    ['Clique aqui para iniciar o chat',    'Deixar uma pergunta ou comentário que iremos responder =)']
        });
      });

      // Tabs
      // $(".tabs-js").tabs();
    }
  };
}(jQuery));
