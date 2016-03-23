<!--.page -->
<div role="document" class="page">

  <!--.l-header region -->
  <header role="banner" class="l-header">
    <div class="header-wrapper">
      <section>
        <div class="logo">
          <?php if ($linked_logo): print $linked_logo; endif; ?>
        </div>

        <div class="main-menu-wrapper">
          <?php if ($alt_main_menu): ?>
            <nav id="main-menu" class="navigation" role="navigation">
              <?php print ($alt_main_menu); ?>
            </nav> <!-- /#main-menu -->
          <?php endif; ?>
        </div>
<!--
        <div class="login-link-wrapper">
          <a href="/user" class="login-link">Login/Registrar</a>
        </div>
 -->
        <div class="logged-header-wrapper">
          <div class="header-blocks">
            <?php print render($page['header']); ?>
          </div>
        </div>
      </section>
    </div>
  </header>
  <!--/.l-header -->

  <?php if (!empty($page['featured'])): ?>
    <!--/.featured -->
    <section class="l-featured">
      <div>
        <?php print render($page['featured']); ?>
      </div>
    </section>
    <!--/.l-featured -->
  <?php endif; ?>

  <?php if ($messages && !$zurb_foundation_messages_modal): ?>
    <!--/.l-messages -->
    <section class="l-messages">
      <div>
        <?php if ($messages): print $messages; endif; ?>
      </div>
    </section>
    <!--/.l-messages -->
  <?php endif; ?>

  <?php if (!empty($page['help'])): ?>
    <!--/.l-help -->
    <section class="l-help">
      <div>
        <?php print render($page['help']); ?>
      </div>
    </section>
    <!--/.l-help -->
  <?php endif; ?>

  <main role="main" class="l-main">
    <div class="main">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlight panel callout">
          <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>

      <a id="main-content"></a>

      <!-- </?php if ($breadcrumb): print $breadcrumb; endif; ?> -->

      <?php if ($title && !$is_front): ?>
        <?php print render($title_prefix); ?>
        <h1 id="page-title" class="title"><?php print $title; ?></h1>
        <?php print render($title_suffix); ?>
      <?php endif; ?>

      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
        <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
      <?php endif; ?>

      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>

      <?php print render($page['content']); ?>
    </div>
    <!--/.main region -->

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside role="complementary" class="sidebar-first sidebar">
        <?php print render($page['sidebar_first']); ?>
      </aside>
    <?php endif; ?>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside role="complementary" class="sidebar-second sidebar">
        <?php print render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>
  </main>
  <!--/.main-->

<!--   </?php if (!empty($page['triptych_first']) || !empty($page['triptych_middle']) || !empty($page['triptych_last'])): ?>
    <section class="l-triptych row">
      <div class="triptych-first large-4 columns">
        </?php print render($page['triptych_first']); ?>
      </div>
      <div class="triptych-middle large-4 columns">
        </?php print render($page['triptych_middle']); ?>
      </div>
      <div class="triptych-last large-4 columns">
        </?php print render($page['triptych_last']); ?>
      </div>
    </section>
  </?php endif; ?> -->
<!--
  </?php if (!empty($page['footer_firstcolumn']) || !empty($page['footer_secondcolumn']) || !empty($page['footer_thirdcolumn']) || !empty($page['footer_fourthcolumn'])): ?>
    <section class="row l-footer-columns">
      </?php if (!empty($page['footer_firstcolumn'])): ?>
        <div class="footer-first large-3 columns">
          </?php print render($page['footer_firstcolumn']); ?>
        </div>
      </?php endif; ?>
      </?php if (!empty($page['footer_secondcolumn'])): ?>
        <div class="footer-second large-3 columns">
          </?php print render($page['footer_secondcolumn']); ?>
        </div>
      </?php endif; ?>
      </?php if (!empty($page['footer_thirdcolumn'])): ?>
        <div class="footer-third large-3 columns">
          </?php print render($page['footer_thirdcolumn']); ?>
        </div>
      </?php endif; ?>
      </?php if (!empty($page['footer_fourthcolumn'])): ?>
        <div class="footer-fourth large-3 columns">
          </?php print render($page['footer_fourthcolumn']); ?>
        </div>
      </?php endif; ?>
    </section>
  </?php endif; ?>
 -->
  <!--.l-footer-->
  <footer class="l-footer panel" role="contentinfo">
    <div class="main-footer-wrapper">
      <?php if (!empty($page['footer'])): ?>
        <div class="footer">
          <?php print render($page['footer']); ?>
        </div>
      <?php endif; ?>

      <?php if ($site_name) :?>
        <div class="copyright">
          &copy; <?php print date('Y') . ' ' . check_plain($site_name) . ' ' . t('All rights reserved.'); ?>
        </div>
      <?php endif; ?>
    </div>
  </footer>
  <!--/.footer-->

  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div>
<!--/.page -->
