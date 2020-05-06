<?php

namespace Drupal\Tests\stanford_news\Unit\Plugin\Block;

use Drupal\stanford_news\Plugin\Block\SignupBlock;
use Drupal\Tests\UnitTestCase;

/**
 * Class SignupBlockTest.
 *
 * @group stanford_news
 * @coversDefaultClass \Drupal\stanford_news\Plugin\Block\SignupBlock
 */
class SignupBlockTest extends UnitTestCase {

  /**
   * @var \Drupal\stanford_news\Plugin\Block\SignupBlock
   */
  protected $blockObject;

  /**
   * {@inheritDoc}
   */
  protected function setUp() {
    parent::setUp();
    $config = [
      "id" => "signup_block",
      "label" => "Newsletter Signup",
      "label_display" => "visible",
      "form_action" => "my-form-action"
    ];
    $this->blockObject = new SignupBlock($config, '', ["provider" => "stanford_news"]);
  }

  public function testBlockMethod() {
    $build = $this->blockObject->build();
    $config = [
      "id" => "signup_block",
      "label" => "Newsletter Signup",
      "provider" => "stanford_news",
      "label_display" => "visible",
      "form_action" => "my-form-action"
    ];
    $this->assertArrayEquals(['#theme' => 'signup_block', '#configuration' => $config], $build);
  }

}
